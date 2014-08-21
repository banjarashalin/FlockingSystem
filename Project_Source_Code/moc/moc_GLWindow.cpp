/****************************************************************************
** Meta object code from reading C++ file 'GLWindow.h'
**
** Created: Mon Apr 4 10:48:49 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GLWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   10,    9,    9, 0x0a,
      71,   55,    9,    9, 0x0a,
     120,  104,    9,    9, 0x0a,
     170,  151,    9,    9, 0x0a,
     222,  204,    9,    9, 0x0a,
     265,  255,    9,    9, 0x0a,
     295,  285,    9,    9, 0x0a,
     317,  315,    9,    9, 0x0a,
     331,  315,    9,    9, 0x0a,
     359,  348,    9,    9, 0x0a,
     390,  380,    9,    9, 0x0a,
     415,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWindow[] = {
    "GLWindow\0\0_alignWeight\0"
    "setFlockAlignmentWeight(double)\0"
    "_seperateWeight\0setFlockSeperationWeight(double)\0"
    "_cohesionWeight\0setFlockCohesionWeight(double)\0"
    "_neighbourdistance\0setFlockNeighboutDistance(double)\0"
    "_seperatedistance\0setFlockSeperateDistance(double)\0"
    "_minspeed\0setMinSpeed(double)\0_maxspeed\0"
    "setMaxSpeed(double)\0i\0addBoids(int)\0"
    "removeBoids(int)\0_boidscale\0"
    "setboidScale(double)\0_boidtype\0"
    "setboidType(std::string)\0resetBoids()\0"
};

const QMetaObject GLWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWindow,
      qt_meta_data_GLWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWindow))
        return static_cast<void*>(const_cast< GLWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setFlockAlignmentWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: setFlockSeperationWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: setFlockCohesionWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: setFlockNeighboutDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: setFlockSeperateDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: setMinSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: setMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: addBoids((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: removeBoids((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: setboidScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: setboidType((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 11: resetBoids(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
