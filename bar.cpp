#include "bar.h"
#include <QRect>
Bar::Bar()
{

}

Bar::Bar(string aName, int aValue, string aCategory ){ //, int aWidth) {
    name = aName;
    value = aValue;
    category = aCategory;
//    width = aWidth;
}
/*
QRectF Bar::boundingRect() const{
    return QRectF(0,0,100,100);
}

void Bar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRoundedRect(0, 0, width, 30, 5, 5);
    painter->drawText(QRect(0,0,width - 10,30),Qt::AlignRight | Qt::AlignVCenter ,QString::fromStdString(name));
//    painter->drawText()
    painter->drawText(QRect(width+10,0,100,30),
                      Qt::AlignLeft | Qt::AlignVCenter ,QString::number(value));

//    painter->drawText(value,0,QString::number(value));
}
*/
