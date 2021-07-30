/****************************************************************************
** Meta object code from reading C++ file 'DownloadDialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ImageScaling/DownloadDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownloadDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DownloadDialog_t {
    const uint offsetsAndSize[10];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DownloadDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DownloadDialog_t qt_meta_stringdata_DownloadDialog = {
    {
QT_MOC_LITERAL(0, 14), // "DownloadDialog"
QT_MOC_LITERAL(15, 12), // "getImageURLS"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 15), // "QList<QString>&"
QT_MOC_LITERAL(45, 9) // "imageUrls"

    },
    "DownloadDialog\0getImageURLS\0\0"
    "QList<QString>&\0imageUrls"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownloadDialog[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    0 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void DownloadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DownloadDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getImageURLS((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DownloadDialog::*)(QList<QString> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DownloadDialog::getImageURLS)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DownloadDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DownloadDialog.offsetsAndSize,
    qt_meta_data_DownloadDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DownloadDialog_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString> &, std::false_type>



>,
    nullptr
} };


const QMetaObject *DownloadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownloadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DownloadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DownloadDialog::getImageURLS(QList<QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
