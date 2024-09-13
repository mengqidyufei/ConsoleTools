#include "EnumBool.h"
#include <QDebug>

EnumBool::EnumBool()
    : QObject()
    , mAttribute(A)
{
    qDebug() << "Maximum value:" << int(8*sizeof(uint));
    setAttribute(EnumBool::B, true);
    setAttribute(EnumBool::C, true);
    qDebug() << "Attribute:" << mAttribute;
}

void EnumBool::setAttribute(int attribute, bool on)
{
    if (on)
        mAttribute = (mAttribute | attribute);
    else
        mAttribute = (mAttribute & ~attribute);
}
