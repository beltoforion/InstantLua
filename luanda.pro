#-------------------------------------------------
#
# Project created by QtCreator 2011-02-15T23:13:14
#
#-------------------------------------------------


QT       += core gui

# Lua sollte nicht mit gcc compiliert werden!

QMAKE_CC = g++

TARGET = luanda
TEMPLATE = app
DEFINES += _CRT_SECURE_NO_WARNINGS \
    QT \
    SCI_LEXER

# set up custom build directory
CONFIG(debug, debug|release) {
    DESTDIR = ./build/debug
    OBJECTS_DIR = ./build/debug/.obj
    MOC_DIR = ./build/debug/.moc
    RCC_DIR = ./build/debug/.rcc
#    UI_DIR = ./build/debug/.ui
} else {
    DESTDIR = ./build/release
    OBJECTS_DIR = ./build/release/.obj
    MOC_DIR = ./build/release/.moc
    RCC_DIR = ./build/release/.rcc
#    UI_DIR = ./build/release/.ui
}

SOURCES += main.cpp\
    3rdparty/lua-5.2.1/src/lzio.c \
    3rdparty/lua-5.2.1/src/lvm.c \
    3rdparty/lua-5.2.1/src/lundump.c \
    3rdparty/lua-5.2.1/src/ltm.c \
    3rdparty/lua-5.2.1/src/ltablib.c \
    3rdparty/lua-5.2.1/src/ltable.c \
    3rdparty/lua-5.2.1/src/lstrlib.c \
    3rdparty/lua-5.2.1/src/lstring.c \
    3rdparty/lua-5.2.1/src/lstate.c \
    3rdparty/lua-5.2.1/src/lparser.c \
    3rdparty/lua-5.2.1/src/loslib.c \
    3rdparty/lua-5.2.1/src/lopcodes.c \
    3rdparty/lua-5.2.1/src/lobject.c \
    3rdparty/lua-5.2.1/src/loadlib.c \
    3rdparty/lua-5.2.1/src/lmem.c \
    3rdparty/lua-5.2.1/src/lmathlib.c \
    3rdparty/lua-5.2.1/src/llex.c \
    3rdparty/lua-5.2.1/src/liolib.c \
    3rdparty/lua-5.2.1/src/linit.c \
    3rdparty/lua-5.2.1/src/lgc.c \
    3rdparty/lua-5.2.1/src/lfunc.c \
    3rdparty/lua-5.2.1/src/ldump.c \
    3rdparty/lua-5.2.1/src/ldo.c \
    3rdparty/lua-5.2.1/src/ldebug.c \
    3rdparty/lua-5.2.1/src/ldblib.c \
    3rdparty/lua-5.2.1/src/lctype.c \
    3rdparty/lua-5.2.1/src/lcorolib.c \
    3rdparty/lua-5.2.1/src/lcode.c \
    3rdparty/lua-5.2.1/src/lbitlib.c \
    3rdparty/lua-5.2.1/src/lbaselib.c \
    3rdparty/lua-5.2.1/src/lauxlib.c \
    3rdparty/lua-5.2.1/src/lapi.c \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/ScintillaQt.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/SciClasses.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscistyledtext.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscistyle.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qsciscintillabase.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qsciscintilla.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qsciprinter.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscimacro.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexeryaml.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerxml.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexervhdl.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerverilog.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexertex.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexertcl.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexersql.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerspice.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerruby.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerpython.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerproperties.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerpov.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerpostscript.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerperl.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerpascal.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexeroctave.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexermatlab.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexermakefile.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerlua.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerjavascript.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerjava.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexeridl.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerhtml.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerfortran77.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerfortran.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerdiff.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerd.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexercustom.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexercss.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexercsharp.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexercpp.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexercmake.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerbatch.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexerbash.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscilexer.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscidocument.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscicommandset.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qscicommand.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qsciapis.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/qsciabstractapis.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/PlatQt.cpp \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/ListBoxQt.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/WordList.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/StyleContext.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/PropSetSimple.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerSimple.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerNoExceptions.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerModule.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerBase.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/CharacterSet.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/Accessor.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexYAML.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexVHDL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexVerilog.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexVB.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexTxt2tags.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexTeX.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexTCL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexTAL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexTADS3.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexTACL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexSQL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexSpice.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexSpecman.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexSorcus.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexSML.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexSmalltalk.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexScriptol.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexRuby.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexRebol.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexR.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPython.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPS.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexProgress.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPowerShell.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPowerPro.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPOV.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPLM.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPerl.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPB.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexPascal.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexOthers.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexOpal.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexNsis.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexNimrod.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMySQL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMSSQL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMPT.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexModula.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMMIXAL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMetapost.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMatlab.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMarkdown.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexMagik.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexLua.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexLout.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexLisp.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexKix.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexInno.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexHTML.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexHaskell.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexGui4Cli.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexGAP.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexFortran.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexForth.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexFlagship.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexEScript.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexErlang.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexEiffel.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexD.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCSS.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCsound.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCrontab.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCPP.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexConf.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCOBOL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCmake.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCLW.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexCaml.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexBullant.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexBasic.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexBash.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexBaan.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAVE.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAU3.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexASY.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAsn1.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAsm.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAPDL.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAda.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexAbaqus.cpp \
    3rdparty/QScintilla-gpl-2.6.2/lexers/LexA68k.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/XPM.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/ViewStyle.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/UniConversion.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Style.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Selection.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/ScintillaBase.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/RunStyles.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/RESearch.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/PositionCache.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/PerLine.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/LineMarker.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/KeyMap.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Indicator.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/ExternalLexer.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Editor.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Document.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Decoration.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/ContractionState.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/CharClassify.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/CellBuffer.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/Catalogue.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/CallTip.cpp \
    3rdparty/QScintilla-gpl-2.6.2/src/AutoComplete.cpp \
    IFile.cpp \
    Settings.cpp \
    FileLua.cpp \
    DlgSettings.cpp \
    ISettingsProvider.cpp \
    IProject.cpp \
    ProjectLua.cpp \
    IFileObserver.cpp \
    FrmSourceEdit.cpp \
    FrmProjectExplorer.cpp \
    FrmInfo.cpp \
    FrmFileExplorer.cpp \
    WndMain.cpp \
    FileExplorerTabWidget.cpp \
    DlgAbout.cpp \
    FrmConsole.cpp \
    Utils.cpp \
    Exceptions.cpp \
    QCommandPrompt.cpp \
    Prototypes.cpp \
    QFileExplorerTabBar.cpp \
    QGradientPanel.cpp \
    QSelection.cpp \
    luabind/LuaValues.cpp \
    luabind/LuaContext.cpp \
    luabind/ILuaValue.cpp \
    QConsoleStreamBuffer.cpp

HEADERS  += \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/ListBoxQt.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/SciClasses.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/SciNamespace.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/ScintillaQt.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/WordList.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/StyleContext.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/SparseState.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/PropSetSimple.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/OptionSet.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerSimple.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerNoExceptions.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerModule.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexerBase.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/LexAccessor.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/CharacterSet.h \
    3rdparty/QScintilla-gpl-2.6.2/lexlib/Accessor.h \
    3rdparty/QScintilla-gpl-2.6.2/include/ScintillaWidget.h \
    3rdparty/QScintilla-gpl-2.6.2/include/Scintilla.h \
    3rdparty/QScintilla-gpl-2.6.2/include/SciLexer.h \
    3rdparty/QScintilla-gpl-2.6.2/include/Platform.h \
    3rdparty/QScintilla-gpl-2.6.2/include/ILexer.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscistyledtext.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscistyle.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qsciscintillabase.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qsciscintilla.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qsciprinter.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscimacro.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexeryaml.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerxml.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexervhdl.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerverilog.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexertex.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexertcl.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexersql.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerspice.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerruby.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerpython.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerproperties.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerpov.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerpostscript.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerperl.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerpascal.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexeroctave.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexermatlab.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexermakefile.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerlua.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerjavascript.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerjava.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexeridl.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerhtml.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerfortran77.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerfortran.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerdiff.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerd.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexercustom.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexercss.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexercsharp.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexercpp.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexercmake.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerbatch.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexerbash.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscilexer.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qsciglobal.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscidocument.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscicommandset.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qscicommand.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qsciapis.h \
    3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/Qsci/qsciabstractapis.h \
    3rdparty/QScintilla-gpl-2.6.2/src/XPM.h \
    3rdparty/QScintilla-gpl-2.6.2/src/ViewStyle.h \
    3rdparty/QScintilla-gpl-2.6.2/src/UniConversion.h \
    3rdparty/QScintilla-gpl-2.6.2/src/SVector.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Style.h \
    3rdparty/QScintilla-gpl-2.6.2/src/SplitVector.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Selection.h \
    3rdparty/QScintilla-gpl-2.6.2/src/ScintillaBase.h \
    3rdparty/QScintilla-gpl-2.6.2/src/RunStyles.h \
    3rdparty/QScintilla-gpl-2.6.2/src/RESearch.h \
    3rdparty/QScintilla-gpl-2.6.2/src/PositionCache.h \
    3rdparty/QScintilla-gpl-2.6.2/src/PerLine.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Partitioning.h \
    3rdparty/QScintilla-gpl-2.6.2/src/LineMarker.h \
    3rdparty/QScintilla-gpl-2.6.2/src/KeyMap.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Indicator.h \
    3rdparty/QScintilla-gpl-2.6.2/src/FontQuality.h \
    3rdparty/QScintilla-gpl-2.6.2/src/ExternalLexer.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Editor.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Document.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Decoration.h \
    3rdparty/QScintilla-gpl-2.6.2/src/ContractionState.h \
    3rdparty/QScintilla-gpl-2.6.2/src/CharClassify.h \
    3rdparty/QScintilla-gpl-2.6.2/src/CellBuffer.h \
    3rdparty/QScintilla-gpl-2.6.2/src/Catalogue.h \
    3rdparty/QScintilla-gpl-2.6.2/src/CallTip.h \
    3rdparty/QScintilla-gpl-2.6.2/src/AutoComplete.h \
    IFile.h \
    Types.h \
    Settings.h \
    IFileObserver.h \
    IObserveable.h \
    IProject.h \
    ISettingsProvider.h \
    FileLua.h \
    ProjectLua.h \
    DlgSettings.h \
    FwdDecl.h \
    FrmSourceEdit.h \
    FrmProjectExplorer.h \
    FrmInfo.h \
    FrmFileExplorer.h \
    WndMain.h \
    FileExplorerTabWidget.h \
    DlgAbout.h \
    FrmConsole.h \
    Utils.h \
    Exceptions.h \
    QCommandPrompt.h \
    Prototypes.h \
    QFileExplorerTabBar.h \
    QGradientPanel.h \
    QSelection.h \
    luabind/LuaValues.h \
    luabind/LuaContext.h \
    luabind/ILuaValue.h \
    3rdparty/lua-5.2.1/src/lzio.h \
    3rdparty/lua-5.2.1/src/lvm.h \
    3rdparty/lua-5.2.1/src/lundump.h \
    3rdparty/lua-5.2.1/src/lualib.h \
    3rdparty/lua-5.2.1/src/luaconf.h \
    3rdparty/lua-5.2.1/src/lua.hpp \
    3rdparty/lua-5.2.1/src/lua.h \
    3rdparty/lua-5.2.1/src/ltm.h \
    3rdparty/lua-5.2.1/src/ltable.h \
    3rdparty/lua-5.2.1/src/lstring.h \
    3rdparty/lua-5.2.1/src/lstate.h \
    3rdparty/lua-5.2.1/src/lparser.h \
    3rdparty/lua-5.2.1/src/lopcodes.h \
    3rdparty/lua-5.2.1/src/lobject.h \
    3rdparty/lua-5.2.1/src/lmem.h \
    3rdparty/lua-5.2.1/src/llimits.h \
    3rdparty/lua-5.2.1/src/llex.h \
    3rdparty/lua-5.2.1/src/lgc.h \
    3rdparty/lua-5.2.1/src/lfunc.h \
    3rdparty/lua-5.2.1/src/ldo.h \
    3rdparty/lua-5.2.1/src/ldebug.h \
    3rdparty/lua-5.2.1/src/lctype.h \
    3rdparty/lua-5.2.1/src/lcode.h \
    3rdparty/lua-5.2.1/src/lauxlib.h \
    3rdparty/lua-5.2.1/src/lapi.h \
    IInterpreter.h \
    QConsoleStreamBuffer.h \
    IConsole.h

FORMS    += \
    DlgSettings.ui \
    WndMain.ui \
    FrmFileExplorer.ui \
    FrmInfo.ui \
    FrmProjectExplorer.ui \
    DlgAbout.ui \
    FrmConsole.ui \
    QGradientPanel.ui \
    QSelection.ui

INCLUDEPATH += $$PWD/3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5 \
    $$PWD/3rdparty/QScintilla-gpl-2.6.2/include \
    $$PWD/3rdparty/QScintilla-gpl-2.6.2/src \
    $$PWD/3rdparty/QScintilla-gpl-2.6.2/lexlib \
    $$PWD/3rdparty/lua-5.2.1/src

CONFIG += thread release

debug {
    CONFIG -= release
    message(DEBUG build for windows)
    LIBS += -Llib
}

release {
    message(RELEASE build for windows)
    LIBS += -Llib
}



#LIBS += -lqscintilla2


RESOURCES += \
    luanda.qrc


