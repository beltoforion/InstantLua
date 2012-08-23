/****************************************************************************
** Meta object code from reading C++ file 'SciClasses.h'
**
** Created: Sun 19. Aug 22:35:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../3rdparty/QScintilla-gpl-2.6.2/Qt4Qt5/SciClasses.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SciClasses.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QsciSciCallTip[] = {

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

static const char qt_meta_stringdata_QsciSciCallTip[] = {
    "QsciSciCallTip\0"
};

const QMetaObject QsciSciCallTip::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QsciSciCallTip,
      qt_meta_data_QsciSciCallTip, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QsciSciCallTip::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QsciSciCallTip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QsciSciCallTip::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QsciSciCallTip))
        return static_cast<void*>(const_cast< QsciSciCallTip*>(this));
    return QWidget::qt_metacast(_clname);
}

int QsciSciCallTip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QsciSciPopup[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QsciSciPopup[] = {
    "QsciSciPopup\0\0cmd\0on_triggered(int)\0"
};

const QMetaObject QsciSciPopup::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_QsciSciPopup,
      qt_meta_data_QsciSciPopup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QsciSciPopup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QsciSciPopup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QsciSciPopup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QsciSciPopup))
        return static_cast<void*>(const_cast< QsciSciPopup*>(this));
    return QMenu::qt_metacast(_clname);
}

int QsciSciPopup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_QsciSciListBox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QsciSciListBox[] = {
    "QsciSciListBox\0\0handleSelection()\0"
};

const QMetaObject QsciSciListBox::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_QsciSciListBox,
      qt_meta_data_QsciSciListBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QsciSciListBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QsciSciListBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QsciSciListBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QsciSciListBox))
        return static_cast<void*>(const_cast< QsciSciListBox*>(this));
    return QListWidget::qt_metacast(_clname);
}

int QsciSciListBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleSelection(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
