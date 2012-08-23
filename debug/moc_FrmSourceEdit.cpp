/****************************************************************************
** Meta object code from reading C++ file 'FrmSourceEdit.h'
**
** Created: Wed 22. Aug 22:22:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FrmSourceEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrmSourceEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FrmSourceEdit[] = {

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
      21,   15,   14,   14, 0x08,
      40,   14,   14,   14, 0x08,
      57,   55,   14,   14, 0x08,
      81,   78,   14,   14, 0x08,
     147,  129,   14,   14, 0x08,
     192,   14,   14,   14, 0x08,
     206,   14,   14,   14, 0x08,
     227,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FrmSourceEdit[] = {
    "FrmSourceEdit\0\0bStat\0fileModified(bool)\0"
    "linesChanged()\0,\0cursorMoved(int,int)\0"
    ",,\0indicatorClicked(int,int,Qt::KeyboardModifiers)\0"
    "margin,line,state\0"
    "marginClicked(int,int,Qt::KeyboardModifiers)\0"
    "textChanged()\0tabCloseRequest(int)\0"
    "tabChange(int)\0"
};

const QMetaObject FrmSourceEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FrmSourceEdit,
      qt_meta_data_FrmSourceEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FrmSourceEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FrmSourceEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FrmSourceEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FrmSourceEdit))
        return static_cast<void*>(const_cast< FrmSourceEdit*>(this));
    if (!strcmp(_clname, "IFileObserver"))
        return static_cast< IFileObserver*>(const_cast< FrmSourceEdit*>(this));
    return QWidget::qt_metacast(_clname);
}

int FrmSourceEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: linesChanged(); break;
        case 2: cursorMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: indicatorClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3]))); break;
        case 4: marginClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3]))); break;
        case 5: textChanged(); break;
        case 6: tabCloseRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: tabChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
