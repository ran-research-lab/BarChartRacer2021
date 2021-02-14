#include "barchart.h"
#include <QGraphicsRectItem>
#include <iostream>
#include <QString>
using namespace std;

const int BAR_HEIGHT = 30;
const int BAR_MAX_WIDTH = 400;
BarChart::BarChart(){ }

void BarChart::setMap(const multimap<int, string> &m){
    theMap = m;
}

void BarChart::setScene(QGraphicsScene *aScene) {
    scene = aScene;
}

void BarChart::setTitle(const string &aTitle){
    title = aTitle;
}

void BarChart::paint() {

    // we delete all the graphic items in the current scene
    // before inserting the new ones.
    for (auto item: scene->items()) delete item;

    // xf is the factor by which we multiply the values to scale
    // the bars.
    float xf = static_cast<int>(BAR_MAX_WIDTH) / theMap.rbegin()->first;

    QGraphicsSimpleTextItem *txt;

    // title of the bar chart
    txt = new QGraphicsSimpleTextItem(QString::fromStdString(title));
    txt->setPos(25,0);
    txt->setFont(QFont("arial",24));
    txt->setBrush(QBrush(Qt::white));
    scene->addItem(txt);

    // compute the initial y for the bars
    int y = txt->sceneBoundingRect().height();

    // we traverse the multimap in reverse because we want to
    // print the highest value first.

    for (auto it = theMap.rbegin(); it != theMap.rend(); it++) {
        int computedWidth = it->first * xf;

        // the bar
        QGraphicsRectItem *rect = new QGraphicsRectItem();
        rect->setRect(25,y,computedWidth, BAR_HEIGHT);
        rect->setBrush(QBrush(Qt::red));
        scene->addItem(rect);

        // the string label
        txt = new QGraphicsSimpleTextItem(QString::fromStdString(it->second));
        txt->setBrush(QBrush(Qt::white));
        QRectF bR = txt->sceneBoundingRect();
        txt->setPos( 25 + computedWidth - bR.width() - 10, y + BAR_HEIGHT/2 - bR.height()/2 );
        scene->addItem(txt);

        // the number label
        txt = new QGraphicsSimpleTextItem(QString::number(it->first));
        txt->setBrush(QBrush(Qt::white));
        bR = txt->sceneBoundingRect();
        txt->setPos( 25 + computedWidth + bR.width() - 10, y + BAR_HEIGHT/2 - bR.height()/2 );
        scene->addItem(txt);

        y += (BAR_HEIGHT*1.2);
    }
}
