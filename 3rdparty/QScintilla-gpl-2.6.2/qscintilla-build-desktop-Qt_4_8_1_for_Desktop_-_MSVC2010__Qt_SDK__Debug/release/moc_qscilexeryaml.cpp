/****************************************************************************
** Meta object code from reading C++ file 'qscilexeryaml.h'
**
** Created: Wed 8. Aug 21:29:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Qt4Qt5/Qsci/qscilexeryaml.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qscilexeryaml.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QsciLexerYAML[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QsciLexerYAML[] = {
    "QsciLexerYAML\0\0fold\0setFoldComments(bool)\0"
};

void QsciLexerYAML::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QsciLexerYAML *_t = static_cast<QsciLexerYAML *>(_o);
        switch (_id) {
        case 0: _t->setFoldComments((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QsciLexerYAML::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QsciLexerYAML::staticMetaObject = {
    { &QsciLexer::staticMetaObject, qt_meta_stringdata_QsciLexerYAML,
      qt_meta_data_QsciLexerYAML, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QsciLexerYAML::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QsciLexerYAML::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QsciLexerYAML::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QsciLexerYAML))
        return static_cast<void*>(const_cast< QsciLexerYAML*>(this));
    return QsciLexer::qt_metacast(_clname);
}

int QsciLexerYAML::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QsciLexer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
