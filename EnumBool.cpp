#include "EnumBool.h"
#include <QDebug>

EnumBool::EnumBool()
    : QObject()
    , mAttribute(A)
{
    qDebug() << "Maximum value:" << int(8*sizeof(uint));
    setAttribute(EnumBool::B, true);
    setAttribute(EnumBool::E, true);
    qDebug() << "Attribute:" << mAttribute;
    if (mAttribute & E)
    {
        qDebug() << mAttribute << "&" << E << ":" << (mAttribute & E);
    }
}

void EnumBool::setAttribute(int attribute, bool on)
{
    if (on)
        mAttribute = (mAttribute | attribute);
    else
        mAttribute = (mAttribute & ~attribute);
}
