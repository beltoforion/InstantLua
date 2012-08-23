/****************************************************************************
** Meta object code from reading C++ file 'WndMain.h'
**
** Created: Tue 21. Aug 00:06:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WndMain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WndMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WndMain[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,
      71,    8,    8,    8, 0x08,
      97,    8,    8,    8, 0x08,
     123,    8,    8,    8, 0x08,
     150,    8,    8,    8, 0x08,
     167,    8,    8,    8, 0x08,
     200,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WndMain[] = {
    "WndMain\0\0on_actionConsole_triggered()\0"
    "on_actionPreferences_triggered()\0"
    "on_actionQuit_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionAbout_triggered()\0openRecentFile()\0"
    "on_actionOpenProject_triggered()\0"
    "on_actionOpenFile_triggered()\0"
};

const QMetaObject WndMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WndMain,
      qt_meta_data_WndMain, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WndMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WndMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WndMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WndMain))
        return static_cast<void*>(const_cast< WndMain*>(this));
    if (!strcmp(_clname, "ISettingsProvider"))
        return static_cast< ISettingsProvider*>(const_cast< WndMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WndMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionConsole_triggered(); break;
        case 1: on_actionPreferences_triggered(); break;
        case 2: on_actionQuit_triggered(); break;
        case 3: on_actionSave_triggered(); break;
        case 4: on_actionAbout_triggered(); break;
        case 5: openRecentFile(); break;
        case 6: on_actionOpenProject_triggered(); break;
        case 7: on_actionOpenFile_triggered(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
