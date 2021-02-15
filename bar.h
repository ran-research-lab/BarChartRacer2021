#ifndef BAR_H
#define BAR_H
#include <iostream>
#include <QGraphicsRectItem>
#include <QPainter>
using namespace std;
class Bar { //: public QGraphicsItem {
public:
    string name;
    int value;
    string category;
//    int width;
public:
    Bar();
    Bar(string aName, int aValue, string aCategory);//, int aWidth);
    string getName() const;
    int getValue() const;
    string getCategory();
    string toString();
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // BAR_H
