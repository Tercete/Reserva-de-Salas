/****************************************************************************
** Meta object code from reading C++ file 'CModelos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rs/src/CModelos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CModelos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CModelos_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CModelos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CModelos_t qt_meta_stringdata_CModelos = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CModelos"
QT_MOC_LITERAL(1, 9, 6), // "render"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "_id"
QT_MOC_LITERAL(4, 21, 8), // "onAccept"
QT_MOC_LITERAL(5, 30, 7), // "onClose"
QT_MOC_LITERAL(6, 38, 16), // "on_btAdd_clicked"
QT_MOC_LITERAL(7, 55, 17), // "on_btEdit_clicked"
QT_MOC_LITERAL(8, 73, 19) // "on_btDelete_clicked"

    },
    "CModelos\0render\0\0_id\0onAccept\0onClose\0"
    "on_btAdd_clicked\0on_btEdit_clicked\0"
    "on_btDelete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CModelos[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CModelos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CModelos *_t = static_cast<CModelos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->render((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->onAccept(); break;
        case 2: _t->onClose(); break;
        case 3: _t->on_btAdd_clicked(); break;
        case 4: _t->on_btEdit_clicked(); break;
        case 5: _t->on_btDelete_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CModelos::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CModelos.data,
      qt_meta_data_CModelos,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CModelos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CModelos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CModelos.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::Modelos"))
        return static_cast< Ui::Modelos*>(this);
    return QDialog::qt_metacast(_clname);
}

int CModelos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
