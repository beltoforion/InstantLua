/****************************************************************************
** Meta object code from reading C++ file 'DlgSettings.h'
**
** Created: Sun 19. Aug 22:36:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DlgSettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgSettings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x08,
      52,   13,   12,   12, 0x08,
      85,   79,   12,   12, 0x08,
     125,  117,   12,   12, 0x08,
     158,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DlgSettings[] = {
    "DlgSettings\0\0checked\0"
    "on_cbLineNumbers_clicked(bool)\0"
    "on_cbFolding_clicked(bool)\0nSize\0"
    "on_sbFontSize_valueChanged(int)\0nIndent\0"
    "on_sbTabIndent_valueChanged(int)\0"
    "on_btnSelectProjectDir_clicked()\0"
};

const QMetaObject DlgSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgSettings,
      qt_meta_data_DlgSettings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgSettings))
        return static_cast<void*>(const_cast< DlgSettings*>(this));
    if (!strcmp(_clname, "ISettingsProvider"))
        return static_cast< ISettingsProvider*>(const_cast< DlgSettings*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_cbLineNumbers_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_cbFolding_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_sbFontSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_sbTabIndent_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_btnSelectProjectDir_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
