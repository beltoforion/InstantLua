#-------------------------------------------------
#
# Project created by QtCreator 2011-02-15T23:13:14
#
#-------------------------------------------------


QT       += core gui

# Lua sollte nicht mit gcc compiliert werden!

# to force compilation of c files as c++ with gcc:
# (no longer needed as lua files were renamed to cpp)
QMAKE_CC = g++

VERSION = 0.1.0.0
TARGET = InstantLua
TEMPLATE = app
DEFINES += _CRT_SECURE_NO_WARNINGS \
    QT \
    SCI_LEXER \
    APP_VERSION=\\\"$$VERSION\\\"

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
    3rdparty/lua-5.2.1/src/lzio.cpp \
    3rdparty/lua-5.2.1/src/lvm.cpp \
    3rdparty/lua-5.2.1/src/lundump.cpp \
    3rdparty/lua-5.2.1/src/ltm.cpp \
    3rdparty/lua-5.2.1/src/ltablib.cpp \
    3rdparty/lua-5.2.1/src/ltable.cpp \
    3rdparty/lua-5.2.1/src/lstrlib.cpp \
    3rdparty/lua-5.2.1/src/lstring.cpp \
    3rdparty/lua-5.2.1/src/lstate.cpp \
    3rdparty/lua-5.2.1/src/lparser.cpp \
    3rdparty/lua-5.2.1/src/loslib.cpp \
    3rdparty/lua-5.2.1/src/lopcodes.cpp \
    3rdparty/lua-5.2.1/src/lobject.cpp \
    3rdparty/lua-5.2.1/src/loadlib.cpp \
    3rdparty/lua-5.2.1/src/lmem.cpp \
    3rdparty/lua-5.2.1/src/lmathlib.cpp \
    3rdparty/lua-5.2.1/src/llex.cpp \
    3rdparty/lua-5.2.1/src/liolib.cpp \
    3rdparty/lua-5.2.1/src/linit.cpp \
    3rdparty/lua-5.2.1/src/lgc.cpp \
    3rdparty/lua-5.2.1/src/lfunc.cpp \
    3rdparty/lua-5.2.1/src/ldump.cpp \
    3rdparty/lua-5.2.1/src/ldo.cpp \
    3rdparty/lua-5.2.1/src/ldebug.cpp \
    3rdparty/lua-5.2.1/src/ldblib.cpp \
    3rdparty/lua-5.2.1/src/lctype.cpp \
    3rdparty/lua-5.2.1/src/lcorolib.cpp \
    3rdparty/lua-5.2.1/src/lcode.cpp \
    3rdparty/lua-5.2.1/src/lbitlib.cpp \
    3rdparty/lua-5.2.1/src/lbaselib.cpp \
    3rdparty/lua-5.2.1/src/lauxlib.cpp \
    3rdparty/lua-5.2.1/src/lapi.cpp \
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
    luabind/ILuaValue.cpp \
    QConsoleStreamBuffer.cpp \
    luabind/LuaWorker.cpp \
    Locker.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexYAML.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexVisualProlog.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexVHDL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexVerilog.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexVB.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTxt2tags.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTeX.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTCMD.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTCL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTAL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTADS3.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexTACL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexSQL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexSpice.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexSpecman.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexSorcus.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexSML.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexSmalltalk.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexScriptol.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexRuby.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexRebol.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexR.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPython.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPS.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexProgress.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPowerShell.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPowerPro.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPOV.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPO.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPLM.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPerl.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPB.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexPascal.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexOthers.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexOScript.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexOpal.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexNsis.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexNimrod.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMySQL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMSSQL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMPT.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexModula.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMMIXAL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMetapost.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMatlab.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMarkdown.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexMagik.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexLua.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexLout.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexLisp.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexKix.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexInno.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexHTML.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexHaskell.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexGui4Cli.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexGAP.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexFortran.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexForth.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexFlagship.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexEScript.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexErlang.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexEiffel.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexECL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexD.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCSS.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCsound.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCrontab.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCPP.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexConf.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCoffeeScript.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCOBOL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCmake.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCLW.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexCaml.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexBullant.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexBasic.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexBash.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexBaan.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAVS.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAVE.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAU3.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexASY.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAsn1.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAsm.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAPDL.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAda.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexAbaqus.cpp \
    3rdparty/QScintilla-gpl-2.7/lexers/LexA68k.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/WordList.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/StyleContext.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/PropSetSimple.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerSimple.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerNoExceptions.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerModule.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerBase.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/CharacterSet.cpp \
    3rdparty/QScintilla-gpl-2.7/lexlib/Accessor.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/ScintillaQt.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/SciClasses.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscistyledtext.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscistyle.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qsciscintillabase.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qsciscintilla.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qsciprinter.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscimacro.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexeryaml.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerxml.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexervhdl.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerverilog.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexertex.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexertcl.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexersql.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerspice.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerruby.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerpython.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerproperties.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerpov.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerpostscript.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerperl.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerpascal.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexeroctave.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexermatlab.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexermakefile.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerlua.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerjavascript.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerjava.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexeridl.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerhtml.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerfortran77.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerfortran.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerdiff.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerd.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexercustom.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexercss.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexercsharp.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexercpp.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexercmake.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerbatch.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexerbash.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscilexer.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscidocument.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscicommandset.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qscicommand.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qsciapis.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/qsciabstractapis.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/PlatQt.cpp \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/ListBoxQt.cpp \
    3rdparty/QScintilla-gpl-2.7/src/XPM.cpp \
    3rdparty/QScintilla-gpl-2.7/src/ViewStyle.cpp \
    3rdparty/QScintilla-gpl-2.7/src/UniConversion.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Style.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Selection.cpp \
    3rdparty/QScintilla-gpl-2.7/src/ScintillaBase.cpp \
    3rdparty/QScintilla-gpl-2.7/src/RunStyles.cpp \
    3rdparty/QScintilla-gpl-2.7/src/RESearch.cpp \
    3rdparty/QScintilla-gpl-2.7/src/PositionCache.cpp \
    3rdparty/QScintilla-gpl-2.7/src/PerLine.cpp \
    3rdparty/QScintilla-gpl-2.7/src/LineMarker.cpp \
    3rdparty/QScintilla-gpl-2.7/src/KeyMap.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Indicator.cpp \
    3rdparty/QScintilla-gpl-2.7/src/ExternalLexer.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Editor.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Document.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Decoration.cpp \
    3rdparty/QScintilla-gpl-2.7/src/ContractionState.cpp \
    3rdparty/QScintilla-gpl-2.7/src/CharClassify.cpp \
    3rdparty/QScintilla-gpl-2.7/src/CellBuffer.cpp \
    3rdparty/QScintilla-gpl-2.7/src/Catalogue.cpp \
    3rdparty/QScintilla-gpl-2.7/src/CallTip.cpp \
    3rdparty/QScintilla-gpl-2.7/src/AutoComplete.cpp \
    luabind/LuaTabWindow.cpp \
    luabind/ILuaTable.cpp \
    luabind/LuaExtensions.cpp \
    luabind/LuaTabSys.cpp \
    luabind/ILuaAction.cpp \
    luabind/LuaTabMessageBox.cpp \
    luabind/LuaTabCanvas.cpp \
    WndCanvas.cpp \
    QGraphicsItemPointList.cpp \
    DlgNewFile.cpp

HEADERS  += \
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
    QConsoleStreamBuffer.h \
    IConsole.h \
    IMainFrame.h \
    IScriptEngine.h \
    luabind/LuaWorker.h \
    Locker.h \
    3rdparty/QScintilla-gpl-2.7/include/ScintillaWidget.h \
    3rdparty/QScintilla-gpl-2.7/include/Scintilla.h \
    3rdparty/QScintilla-gpl-2.7/include/SciLexer.h \
    3rdparty/QScintilla-gpl-2.7/include/Platform.h \
    3rdparty/QScintilla-gpl-2.7/include/ILexer.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/ScintillaQt.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/SciNamespace.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/SciClasses.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/ListBoxQt.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/WordList.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/StyleContext.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/SparseState.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/PropSetSimple.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/OptionSet.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerSimple.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerNoExceptions.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerModule.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexerBase.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/LexAccessor.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/CharacterSet.h \
    3rdparty/QScintilla-gpl-2.7/lexlib/Accessor.h \
    3rdparty/QScintilla-gpl-2.7/src/XPM.h \
    3rdparty/QScintilla-gpl-2.7/src/ViewStyle.h \
    3rdparty/QScintilla-gpl-2.7/src/UniConversion.h \
    3rdparty/QScintilla-gpl-2.7/src/SVector.h \
    3rdparty/QScintilla-gpl-2.7/src/Style.h \
    3rdparty/QScintilla-gpl-2.7/src/SplitVector.h \
    3rdparty/QScintilla-gpl-2.7/src/Selection.h \
    3rdparty/QScintilla-gpl-2.7/src/ScintillaBase.h \
    3rdparty/QScintilla-gpl-2.7/src/RunStyles.h \
    3rdparty/QScintilla-gpl-2.7/src/RESearch.h \
    3rdparty/QScintilla-gpl-2.7/src/PositionCache.h \
    3rdparty/QScintilla-gpl-2.7/src/PerLine.h \
    3rdparty/QScintilla-gpl-2.7/src/Partitioning.h \
    3rdparty/QScintilla-gpl-2.7/src/LineMarker.h \
    3rdparty/QScintilla-gpl-2.7/src/KeyMap.h \
    3rdparty/QScintilla-gpl-2.7/src/Indicator.h \
    3rdparty/QScintilla-gpl-2.7/src/FontQuality.h \
    3rdparty/QScintilla-gpl-2.7/src/ExternalLexer.h \
    3rdparty/QScintilla-gpl-2.7/src/Editor.h \
    3rdparty/QScintilla-gpl-2.7/src/Document.h \
    3rdparty/QScintilla-gpl-2.7/src/Decoration.h \
    3rdparty/QScintilla-gpl-2.7/src/ContractionState.h \
    3rdparty/QScintilla-gpl-2.7/src/CharClassify.h \
    3rdparty/QScintilla-gpl-2.7/src/CellBuffer.h \
    3rdparty/QScintilla-gpl-2.7/src/Catalogue.h \
    3rdparty/QScintilla-gpl-2.7/src/CallTip.h \
    3rdparty/QScintilla-gpl-2.7/src/AutoComplete.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscistyledtext.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscistyle.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qsciscintillabase.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qsciscintilla.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qsciprinter.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscimacro.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexeryaml.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerxml.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexervhdl.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerverilog.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexertex.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexertcl.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexersql.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerspice.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerruby.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerpython.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerproperties.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerpov.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerpostscript.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerperl.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerpascal.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexeroctave.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexermatlab.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexermakefile.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerlua.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerjavascript.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerjava.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexeridl.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerhtml.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerfortran77.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerfortran.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerdiff.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerd.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexercustom.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexercss.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexercsharp.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexercpp.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexercmake.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerbatch.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexerbash.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscilexer.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qsciglobal.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscidocument.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscicommandset.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qscicommand.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qsciapis.h \
    3rdparty/QScintilla-gpl-2.7/Qt4Qt5/Qsci/qsciabstractapis.h \
    luabind/LuaTabWindow.h \
    luabind/ILuaTable.h \
    luabind/LuaExtensions.h \
    luabind/LuaTabSys.h \
    luabind/ILuaAction.h \
    ISyncContext.h \
    luabind/LuaTabMessageBox.h \
    luabind/LuaTabCanvas.h \
    WndCanvas.h \
    QGraphicsItemPointList.h \
    DlgNewFile.h \
    TryCatch.h

FORMS    += \
    DlgSettings.ui \
    WndMain.ui \
    FrmFileExplorer.ui \
    FrmInfo.ui \
    FrmProjectExplorer.ui \
    DlgAbout.ui \
    FrmConsole.ui \
    QGradientPanel.ui \
    QSelection.ui \
    WndCanvas.ui \
    DlgNewFile.ui

INCLUDEPATH += $$PWD/3rdparty/QScintilla-gpl-2.7/Qt4Qt5 \
    $$PWD/3rdparty/QScintilla-gpl-2.7/include \
    $$PWD/3rdparty/QScintilla-gpl-2.7/src \
    $$PWD/3rdparty/QScintilla-gpl-2.7/lexlib \
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


