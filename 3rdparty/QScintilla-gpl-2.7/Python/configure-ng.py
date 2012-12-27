# This script configures QScintilla for PyQt v4.10 and later.  It will fall
# back to the old script if an earlier version of PyQt is found.
#
# Copyright (c) 2012 Riverbank Computing Limited <info@riverbankcomputing.com>
# 
# This file is part of QScintilla.
# 
# This file may be used under the terms of the GNU General Public
# License versions 2.0 or 3.0 as published by the Free Software
# Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
# included in the packaging of this file.  Alternatively you may (at
# your option) use any later version of the GNU General Public
# License if such license has been publicly approved by Riverbank
# Computing Limited (or its successors, if any) and the KDE Free Qt
# Foundation. In addition, as a special exception, Riverbank gives you
# certain additional rights. These rights are described in the Riverbank
# GPL Exception version 1.1, which can be found in the file
# GPL_EXCEPTION.txt in this package.
# 
# If you are unsure which license is appropriate for your use, please
# contact the sales department at sales@riverbankcomputing.com.
# 
# This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
# WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.


import sys
import os
import glob
import optparse

try:
    import sysconfig
except ImportError:
    from distutils import sysconfig


# Initialise the constants.
SIP_MIN_VERSION = '4.12.0'

# This must be kept in sync with qscintilla.pro.
QSCI_API_MAJOR = 9


if sys.platform == "win32":
    qsci_define = "QSCINTILLA_DLL"
else:
    qsci_define = ""


def error(msg):
    """ Display an error message and terminate.  msg is the text of the error
    message.
    """

    sys.stderr.write(format("Error: " + msg) + "\n")
    sys.exit(1)


def inform(msg):
    """ Display an information message.  msg is the text of the error message.
    """

    sys.stdout.write(format(msg) + "\n")


def format(msg, left_margin=0, right_margin=78):
    """ Format a message by inserting line breaks at appropriate places.  msg
    is the text of the message.  left_margin is the position of the left
    margin.  right_margin is the position of the right margin.  Returns the
    formatted message.
    """

    curs = left_margin
    fmsg = " " * left_margin

    for w in msg.split():
        l = len(w)
        if curs != left_margin and curs + l > right_margin:
            fmsg = fmsg + "\n" + (" " * left_margin)
            curs = left_margin

        if curs > left_margin:
            fmsg = fmsg + " "
            curs = curs + 1

        fmsg = fmsg + w
        curs = curs + l

    return fmsg


class NativePythonConfiguration:
    """ A container for the native Python configuration. """

    def __init__(self):
        """ Initialise the configuration. """

        if hasattr(sysconfig, 'get_path'):
            # The modern API.
            self.module_dir = sysconfig.get_path('platlib')
        else:
            # The legacy distutils API.
            self.module_dir = sysconfig.get_python_lib(plat_specific=1)

        if sys.platform == 'win32':
            self.data_dir = sys.prefix
        else:
            self.data_dir = sys.prefix + '/share'


class TargetQtConfiguration:
    """ A container for the target Qt configuration. """

    def __init__(self, qmake):
        """ Initialise the configuration.  qmake is the full pathname of the
        qmake executable that will provide the configuration.
        """

        pipe = os.popen(' '.join([qmake, '-query']))

        for l in pipe:
            l = l.strip()

            tokens = l.split(':', 1)
            if isinstance(tokens, list):
                if len(tokens) != 2:
                    error("Unexpected output from qmake: '%s'\n" % l)

                name, value = tokens
            else:
                name = tokens
                value = None

            name = name.replace('/', '_')

            setattr(self, name, value)

        pipe.close()


class TargetConfiguration:
    """ A container for the target configuration. """

    def __init__(self):
        """ Initialise the configuration with default values. """

        # Values based on the native Python configuration.
        py_config = NativePythonConfiguration()
        self.module_dir = os.path.join(py_config.module_dir, 'PyQt4')
        self.pyqt_sip_dir = os.path.join(py_config.data_dir, 'sip', 'PyQt4')
        self.sip_dir = self.pyqt_sip_dir

        # Remaining values.
        self.platform = sys.platform
        self.pyqt_sip_flags = ''
        self.pyqt_version = ''
        self.qmake = self._find_exe('qmake')
        self.sip = self._find_exe('sip')

        self.prot_is_public = (self.platform.startswith('linux') or self.platform == 'darwin')

    def from_configuration_file(self, config_file):
        """ Initialise the configuration with values from a file.  config_file
        is the name of the configuration file.
        """

        inform("Reading configuration from %s..." % config_file)

        cfg = open(config_file)
        line_nr = 0

        for l in cfg:
            line_nr += 1
            l = l.strip()

            if len(l) == 0 or l[0] == '#':
                continue

            eq = l.find('=')
            if eq > 0:
                name = l[:eq - 1].rstrip()
                value = l[eq + 1:].lstrip()
            else:
                name = value = ''

            if name == '' or value == '':
                error("%s:%d: Invalid line." % (config_file, line_nr))

            default_value = getattr(self, name, None)
            if default_value is None:
                error(
                        "%s:%d: Unknown item: %s." % (config_file, line_nr,
                                name))

            if isinstance(default_value, int):
                if value.startswith('0x'):
                    value = int(value, 16)
                else:
                    value = int(value)

            setattr(self, name, value)

        cfg.close()

    def from_introspection(self):
        """ Initialise the configuration by introspecting the system. """

        from PyQt4 import QtCore

        inform("PyQt %s is being used." % QtCore.PYQT_VERSION_STR)
        inform("Qt %s is being used." % QtCore.QT_VERSION_STR)

        # See if we have a PyQt4 that embeds its configuration.
        try:
            pyqt_config = QtCore.PYQT_CONFIGURATION
        except AttributeError:
            pyqt_config = None

        # FIXME: During development.
        pyqt_config = dict(sip_flags='-x VendorID -t WS_MACX -x PyQt_NoPrintRangeBug -t Qt_4_8_3')

        if pyqt_config is None:
            # Fallback to the old configuration script.
            # FIXME: When the scripts are renamed.
            config_script = sys.argv[0].replace('configure-ng', 'configure')
            args = [sys.executable, config_script] + sys.argv[1:]

            try:
                os.execv(sys.executable, args)
            except OSError:
                pass

            error("Unable to execute '%s'\n" % config_script)

        self.pyqt_sip_flags = pyqt_config['sip_flags']

    def override_defaults(self, opts):
        """ Override the default from the command line.  opts are the command
        line options.
        """

        # Values from the target Qt configuration.
        try:
            qmake = opts.qmake
        except AttributeError:
            # Windows.
            qmake = None

        if qmake is not None:
            self.qmake = qmake
        elif self.qmake is None:
            # Under Windows qmake and the Qt DLLs must be on the system PATH
            # otherwise the dynamic linker won't be able to resolve the
            # symbols.  On other systems we assume we can just run qmake by
            # using its full pathname.
            if sys.platform == 'win32':
                error("Make sure you have a working Qt qmake on your PATH.")
            else:
                error(
                        "Make sure you have a working Qt qmake on your PATH "
                        "or use the --qmake argument to explicitly specify a "
                        "working Qt qmake.")

        qt_config = TargetQtConfiguration(self.qmake)
        self.api_dir = qt_config.QT_INSTALL_DATA
        self.header_dir = qt_config.QT_INSTALL_HEADERS
        self.lib_dir = qt_config.QT_INSTALL_LIBS

        # Override from the command line.
        if opts.apidir is not None:
            self.api_dir = opts.apidir

        inform("The QScintilla API file will be installed in %s." %
                os.path.join(self.api_dir, 'api', 'python'))

        if opts.destdir is not None:
            self.module_dir = opts.destdir

        inform("The QScintilla module will be installed in %s." %
                self.module_dir)

        if opts.prot_is_public is not None:
            self.prot_is_public = opts.prot_is_public

        if self.prot_is_public:
            inform("The QScintilla module is being built with 'protected' "
                    "redefined as 'public'.")

        if opts.qsci_incdir is not None:
            self.header_dir = opts.qsci_incdir

        if opts.qsci_libdir is not None:
            self.lib_dir = opts.qsci_libdir

        if opts.qsci_sipdir is not None:
            self.sip_dir = opts.qsci_sipdir

        inform("The QScintilla .sip files will be installed in %s." %
                self.sip_dir)

        if opts.sip is not None:
            self.sip = opts.sip

    @staticmethod
    def _find_exe(exe):
        """ Find an executable, ie. the first on the path. """

        try:
            path = os.environ['PATH']
        except KeyError:
            path = ''

        if sys.platform == 'win32':
            exe = exe + '.exe'

        for d in path.split(os.pathsep):
            exe_path = os.path.join(d, exe)

            if os.access(exe_path, os.X_OK):
                return exe_path

        return None


def create_optparser(target_config):
    """ Create the parser for the command line.  target_config is the target
    configuration containing default values.
    """

    def store_abspath_file(option, opt_str, value, parser):
        setattr(parser.values, option.dest, os.path.abspath(value))

    def store_abspath_dir(option, opt_str, value, parser):
        if not os.path.isdir(value):
            raise optparse.OptionValueError("'%s' is not a directory" % value)
        setattr(parser.values, option.dest, os.path.abspath(value))

    def store_abspath_exe(option, opt_str, value, parser):
        if not os.access(value, os.X_OK):
            raise optparse.OptionValueError("'%s' is not an executable" % value)
        setattr(parser.values, option.dest, os.path.abspath(value))

    p = optparse.OptionParser(usage="python %prog [options]",
            version="2.7")

    p.add_option("--apidir", "-a", dest='apidir', type='string', default=None,
            action='callback', callback=store_abspath_file, metavar="DIR", 
            help="the QScintilla API file will be installed in DIR [default: "
                    "QT_INSTALL_DATA/qsci]")
    p.add_option("--configuration", dest='config_file', type='string',
            default=None, action='callback', callback=store_abspath_file,
            metavar="FILE",
            help="FILE defines the target configuration")
    p.add_option("--destdir", "-d", dest='destdir', type='string',
            default=None, action='callback', callback=store_abspath_file,
            metavar="DIR",
            help="install the QScintilla module in DIR [default: "
                    "%s]" % target_config.module_dir)
    p.add_option("--protected-is-public", dest='prot_is_public', default=None,
            action='store_true',
            help="enable building with 'protected' redefined as 'public' "
                    "[default: %s]" % target_config.prot_is_public)
    p.add_option("--protected-not-public", dest='prot_is_public',
            action='store_false',
            help="disable building with 'protected' redefined as 'public'")

    if sys.platform != 'win32':
        p.add_option("--qmake", "-q", dest='qmake', type='string',
                default=None, action='callback', callback=store_abspath_exe,
                metavar="FILE",
                help="the pathname of qmake is FILE [default: "
                        "%s]" % (target_config.qmake or "None"))

    p.add_option("--qsci-incdir", "-n", dest='qsci_incdir', type='string',
            default=None, action='callback', callback=store_abspath_dir,
            metavar="DIR",
            help="the directory containing the QScintilla Qsci header file "
                    "directory is DIR [default: QT_INSTALL_HEADERS]")
    p.add_option("--qsci-libdir", "-o", dest='qsci_libdir', type='string',
            default=None, action='callback', callback=store_abspath_dir,
            metavar="DIR",
            help="the directory containing the QScintilla library is DIR "
                    "[default: QT_INSTALL_LIBS]")
    p.add_option("--sip", dest='sip', type='string', default=None,
            action='callback', callback=store_abspath_exe, metavar="FILE",
            help="the pathname of sip is FILE [default: "
                    "%s]" % (target_config.sip or "None"))
    p.add_option("--sipdir", "-v", dest='qsci_sipdir', type='string',
            default=None, action='callback', callback=store_abspath_dir,
            metavar="DIR",
            help="the QScintilla .sip files will be installed in DIR "
                    "[default: %s]" % target_config.sip_dir)

    p.add_option("-c", "--concatenate", action='store_true', default=False,
            dest='concat', help="concatenate the C++ source files")
    p.add_option("-j", "--concatenate-split", type="int", default=1,
            metavar="N", dest="split", help="split the concatenated C++ "
            "source files into N pieces [default: 1]")
    p.add_option("-k", "--static", action="store_true", default=False,
            dest="static", help="build the QScintilla module as a static "
            "library")
    p.add_option("--no-docstrings", action="store_true", default=False,
            dest="no_docstrings", help="disable the generation of docstrings")
    p.add_option("-r", "--trace", action="store_true", default=False,
            dest="tracing", help="build the QScintilla module with tracing "
            "enabled")
    p.add_option("-s", action="store_true", default=False, dest="not_dll",
            help="QScintilla is a static library and not a DLL (Windows only)")
    p.add_option("-u", "--debug", action="store_true", default=False,
            help="build the QScintilla module with debugging symbols")
    p.add_option("-T", "--no-timestamp", action="store_true", default=False,
            dest="no_timestamp", help="suppress timestamps in the header "
            "comments of generated code [default: include timestamps]")

    return p


def check_qscintilla(target_config):
    """ See if QScintilla can be found and what its version is.  target_config
    is the target configuration.
    """

    # Find the QScintilla header files.
    sciglobal = os.path.join(target_config.header_dir, 'Qsci', 'qsciglobal.h')

    if not os.access(sciglobal, os.F_OK):
        error("Qsci/qsciglobal.h could not be found in %s. If QScintilla is installed then use the --qsci-incdir argument to explicitly specify the correct directory." % target_config.header_dir)

    # Get the QScintilla version string.
    sciversstr = read_define(sciglobal, 'QSCINTILLA_VERSION_STR')
    if sciversstr is None:
        error(
                "The QScintilla version number could not be determined by "
                "reading %s." % sciglobal)

    if not glob.glob(os.path.join(target_config.lib_dir, '*qscintilla2*')):
        error("The QScintilla library could not be found in %s. If QScintilla is installed then use the --qsci-libdir argument to explicitly specify the correct directory." % target_config.lib_dir)

    # Because we include the Python bindings with the C++ code we can
    # reasonably force the same version to be used and not bother about
    # versioning.
    if sciversstr != '2.7':
        error("QScintilla %s is being used but the Python bindings v2.7 are being built. Please use matching versions." % sciversstr)

    inform("QScintilla %s is being used." % sciversstr)


def read_define(filename, define):
    """ Read the value of a #define from a file.  filename is the name of the
    file.  define is the name of the #define.  None is returned if there was no
    such #define.
    """

    f = open(filename)

    for l in f:
        wl = l.split()
        if len(wl) >= 3 and wl[0] == "#define" and wl[1] == define:
            # Take account of embedded spaces.
            value = ' '.join(wl[2:])[1:-1]
            break
    else:
        value = None

    f.close()

    return value


def sip_flags(target_config):
    """ Return the SIP flags.  target_config is the target configuration. """

    # Get the flags used for the main PyQt module.
    flags = target_config.pyqt_sip_flags.split()

    # Generate the API file.
    flags.append("-a")
    flags.append("QScintilla2.api")

    # Add PyQt's .sip files to the search path.
    flags.append("-I")
    flags.append(target_config.pyqt_sip_dir)

    return flags


def generate_code(target_config):
    """ Generate the code for the QScintilla module.  target_config is the
    target configuration.
    """

    mname = "Qsci"

    inform("Generating the C++ source for the %s module..." % mname)

    # Build the SIP command line.
    argv = ['"' + pyqt.sip_bin + '"']

    argv.extend(sip_flags(target_config))

    if opts.no_timestamp:
        argv.append("-T")

    if not opts.no_docstrings:
        argv.append("-o");

    if target_config.prot_is_public:
        argv.append("-P");

    if opts.concat:
        argv.append("-j")
        argv.append(str(opts.split))

    if opts.tracing:
        argv.append("-r")

    argv.append("-c")
    argv.append(".")

    buildfile = os.path.join("qsci.sbf")
    argv.append("-b")
    argv.append(buildfile)

    argv.append("sip/qscimod4.sip")

    os.system(" ".join(argv))

    # Check the result.
    if not os.access(buildfile, os.F_OK):
        error("Unable to create the C++ code.")

    # Generate the Makefile.
    inform("Creating the Makefile for the %s module..." % mname)

    def fix_install(mfile):
        if sys.platform != "darwin" or opts.static:
            return

        mfile.write("\tinstall_name_tool -change libqscintilla2.%u.dylib %s/libqscintilla2.%u.dylib $(DESTDIR)%s/$(TARGET)\n" % (QSCI_API_MAJOR, target_config.lib_dir, QSCI_API_MAJOR, target_config.module_dir))

    class Makefile(pyqt4.QtGuiModuleMakefile):
        def generate_target_install(self, mfile):
            pyqt4.QtGuiModuleMakefile.generate_target_install(self, mfile)
            fix_install(mfile)

    installs = []
    sipfiles = []

    for s in glob.glob("sip/*.sip"):
        sipfiles.append(os.path.join("sip", os.path.basename(s)))

    installs.append([sipfiles, os.path.join(target_config.sip_dir, mname)])

    installs.append(
            ('QScintilla2.api',
                    os.path.join(target_config.api_dir, 'api', 'python')))

    # PyQt v4.2 and later can handle MacOS/X universal binaries.
    if pyqt.pyqt_version >= 0x040200:
        makefile = Makefile(
            configuration=pyqt,
            build_file="qsci.sbf",
            install_dir=target_config.module_dir,
            installs=installs,
            static=opts.static,
            debug=opts.debug,
            universal=pyqt.universal,
            arch=pyqt.arch,
            prot_is_public=target_config.prot_is_public,
            deployment_target=pyqt.deployment_target
        )
    else:
        makefile = Makefile(
            configuration=pyqt,
            build_file="qsci.sbf",
            install_dir=target_config.module_dir,
            installs=installs,
            static=opts.static,
            debug=opts.debug
        )

    if qsci_define:
        makefile.extra_defines.append(qsci_define)

    makefile.extra_include_dirs.append(target_config.header_dir)
    makefile.extra_lib_dirs.append(target_config.lib_dir)
    makefile.extra_libs.append("qscintilla2")

    makefile.generate()


def check_sip(target_config):
    """ Check that the version of sip is good enough.  target_config is the
    target configuration.
    """

    if target_config.sip is None:
        error(
                "Make sure you have a working sip on your PATH or use the "
                "--sip argument to explicitly specify a working sip.")

    pipe = os.popen(' '.join([target_config.sip, '-V']))

    for l in pipe:
        version_str = l.strip()
        break
    else:
        error("'%s -V' did not generate any output." % target_config.sip)

    pipe.close()

    if 'snapshot' not in version_str:
        version = version_from_string(version_str)
        if version is None:
            error(
                    "'%s -V' generated unexpected output: '%s'." % (
                            target_config.sip, version_str))

        min_version = version_from_string(SIP_MIN_VERSION)
        if version < min_version:
            error(
                    "This version of QScintilla requires sip %s or later." %
                            SIP_MIN_VERSION)

    inform("sip %s is being used." % version_str)


def version_from_string(version_str):
    """ Convert a version string of the form m.n or m.n.o to an encoded version
    number (or None if it was an invalid format).  version_str is the version
    string.
    """

    parts = version_str.split('.')
    if not isinstance(parts, list):
        return None

    if len(parts) == 2:
        parts.append('0')

    if len(parts) != 3:
        return None

    version = 0

    for part in parts:
        try:
            v = int(part)
        except ValueError:
            return None

        version = (version << 8) + v

    return version


def main(argv):
    """ Create the configuration module module.  argv is the list of command
    line arguments.
    """

    # Create the default target configuration.
    target_config = TargetConfiguration()

    # Parse the command line.
    p = create_optparser(target_config)
    opts, args = p.parse_args()

    if args:
        p.print_help()
        sys.exit(2)

    # Update the target configuration.
    if opts.config_file is not None:
        target_config.from_configuration_file(opts.config_file)
    else:
        target_config.from_introspection()

    target_config.override_defaults(opts)

    # Check SIP is new enough.
    check_sip(target_config)

    # Provide defaults for platform-specific options.
    if opts.not_dll:
        global qsci_define
        qsci_define = ""

    # Check for QScintilla.
    check_qscintilla(target_config)

    # Generate the code.
    generate_code(target_config)


###############################################################################
# The script starts here.
###############################################################################

if __name__ == "__main__":
    try:
        main(sys.argv)
    except SystemExit:
        raise
    except:
        sys.stderr.write(
"""An internal error occured.  Please report all the output from the program,
including the following traceback, to support@riverbankcomputing.com.
""")
        raise
