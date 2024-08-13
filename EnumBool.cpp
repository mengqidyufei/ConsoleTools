#include "EnumBool.h"
#include <QDebug>

EnumBool::EnumBool()
    : QObject()
    , mAttribute(A)
{
    qDebug() << "Maximum value:" << int(8*sizeof(uint));
    setAttribute(EnumBool::C, true);
    setAttribute(EnumBool::A, true);
    setAttribute(EnumBool::C, false);
    setAttribute(EnumBool::A, false);
    setAttribute(EnumBool::D, true);
    setAttribute(EnumBool::D, false);
}

void EnumBool::setAttribute(int attribute, bool on)
{
    if (attribute < int(8*sizeof(uint)))
    {
       if (on)
           mAttribute |= ( 1 << attribute);
       else
           mAttribute &= ~( 1 << attribute);
       qDebug() << "Attribute:" << mAttribute;
    }
    else
    {
        qDebug() << "Out of range - 32";
//        const int x = attribute - 8*sizeof(uint);
//        const int int_off = x / (8*sizeof(uint));
//        if (on)
//            mHighAttribute[int_off] |= (1<<(x-(int_off*8*sizeof(uint))));
//        else
//            mHighAttribute[int_off] &= ~(1<<(x-(int_off*8*sizeof(uint))));
//        qDebug() << "High attribute:" << mHighAttribute[int_off];
    }
}
