/****************************************************************************
** Meta object code from reading C++ file 'CSalas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rs/src/CSalas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSalas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSalas_t {
    QByteArrayData data[12];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSalas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSalas_t qt_meta_stringdata_CSalas = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CSalas"
QT_MOC_LITERAL(1, 7, 9), // "saveSalas"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 22), // "on_btAdicionar_clicked"
QT_MOC_LITERAL(4, 41, 20), // "on_btAlterar_clicked"
QT_MOC_LITERAL(5, 62, 20), // "on_btExcluir_clicked"
QT_MOC_LITERAL(6, 83, 29), // "on_tbSalas_currentCellChanged"
QT_MOC_LITERAL(7, 113, 10), // "currentRow"
QT_MOC_LITERAL(8, 124, 13), // "currentColumn"
QT_MOC_LITERAL(9, 138, 11), // "previousRow"
QT_MOC_LITERAL(10, 150, 14), // "previousColumn"
QT_MOC_LITERAL(11, 165, 11) // "refreshData"

    },
    "CSalas\0saveSalas\0\0on_btAdicionar_clicked\0"
    "on_btAlterar_clicked\0on_btExcluir_clicked\0"
    "on_tbSalas_currentCellChanged\0currentRow\0"
    "currentColumn\0previousRow\0previousColumn\0"
    "refreshData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSalas[] = {

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
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    4,   48,    2, 0x08 /* Private */,
      11,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void CSalas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSalas *_t = static_cast<CSalas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveSalas(); break;
        case 1: _t->on_btAdicionar_clicked(); break;
        case 2: _t->on_btAlterar_clicked(); break;
        case 3: _t->on_btExcluir_clicked(); break;
        case 4: _t->on_tbSalas_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->refreshData(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSalas::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CSalas.data,
      qt_meta_data_CSalas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CSalas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSalas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSalas.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::Salas"))
        return static_cast< Ui::Salas*>(this);
    return QDialog::qt_metacast(_clname);
}

int CSalas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
