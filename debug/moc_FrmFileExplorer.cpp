/****************************************************************************
** Meta object code from reading C++ file 'FrmFileExplorer.h'
**
** Created: Sun 19. Aug 22:36:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FrmFileExplorer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrmFileExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FrmFileExplorer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      57,   16,   16,   16, 0x08,
      90,   84,   16,   16, 0x08,
     131,  126,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FrmFileExplorer[] = {
    "FrmFileExplorer\0\0"
    "on_actionClose_All_But_This_triggered()\0"
    "on_actionClose_triggered()\0index\0"
    "on_tcProject_tabCloseRequested(int)\0"
    "arg1\0on_tcProject_currentChanged(QWidget*)\0"
};

const QMetaObject FrmFileExplorer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FrmFileExplorer,
      qt_meta_data_FrmFileExplorer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FrmFileExplorer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FrmFileExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FrmFileExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FrmFileExplorer))
        return static_cast<void*>(const_cast< FrmFileExplorer*>(this));
    if (!strcmp(_clname, "ISettingsProvider"))
        return static_cast< ISettingsProvider*>(const_cast< FrmFileExplorer*>(this));
    if (!strcmp(_clname, "IFileObserver"))
        return static_cast< IFileObserver*>(const_cast< FrmFileExplorer*>(this));
    return QWidget::qt_metacast(_clname);
}

int FrmFileExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionClose_All_But_This_triggered(); break;
        case 1: on_actionClose_triggered(); break;
        case 2: on_tcProject_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_tcProject_currentChanged((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
