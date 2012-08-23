/****************************************************************************
** Meta object code from reading C++ file 'DlgAbout.h'
**
** Created: Sun 19. Aug 22:36:26 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DlgAbout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgAbout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgAbout[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_DlgAbout[] = {
    "DlgAbout\0"
};

const QMetaObject DlgAbout::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgAbout,
      qt_meta_data_DlgAbout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgAbout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgAbout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgAbout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgAbout))
        return static_cast<void*>(const_cast< DlgAbout*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgAbout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
