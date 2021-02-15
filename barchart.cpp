#include "barchart.h"
#include <QGraphicsRectItem>
#include <iostream>
#include <QString>
#include "bar.h"
using namespace std;

const int BAR_HEIGHT = 30;
const int BAR_MAX_WIDTH = 400;
BarChart::BarChart(){ }

BarChart::BarChart(string aTitle, string aXLabel, string aSource){
    title = aTitle;
    xAxisLabel = aXLabel;
    dataSource = aSource;
}

void BarChart::setCaption(string aCaption){
    caption = aCaption;
}

void BarChart::add(string name, int value, string category){
    theBars.push_back(Bar(name,value,category));
}

void BarChart::setMap(const multimap<int, string> &m){
    theMap = m;
}

void BarChart::reset()
{
    theBars.clear();
}

void BarChart::setBars(const vector<Bar> &b) {
    theBars = b;
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
    float xf = static_cast<float>(BAR_MAX_WIDTH) / theBars.rbegin()->value;

    QGraphicsSimpleTextItem *txt;

    // title of the bar chart
    txt = new QGraphicsSimpleTextItem(QString::fromStdString(title));
    txt->setFont(QFont("arial",24));
    txt->setBrush(QBrush(Qt::white));

    int txtWidth = txt->sceneBoundingRect().width();
    txt->setPos(400/2 -txtWidth/2,0);
    scene->addItem(txt);
    int y = txt->sceneBoundingRect().height();

    txt = new QGraphicsSimpleTextItem(QString::fromStdString(xAxisLabel));
    txt->setPos(25,y);
    txt->setFont(QFont("arial",16));
    txt->setBrush(QBrush(Qt::white));
    scene->addItem(txt);
    y += txt->sceneBoundingRect().height();

    // caption of the bar chart
    txt = new QGraphicsSimpleTextItem(QString::fromStdString(caption));
    txt->setPos(350,350);
    txt->setFont(QFont("arial",34));
    txt->setBrush(QBrush(Qt::white));
    scene->addItem(txt);

    // compute the initial y for the bars



    // we traverse the multimap in reverse because we want to
    // print the highest value first.
    for (auto e: theBars) {
        // the bar
        int computedWidth = e.value * xf;
        QGraphicsRectItem *rect = new QGraphicsRectItem();
        rect->setRect(25,y,computedWidth, BAR_HEIGHT);
        rect->setBrush(QBrush(Qt::red));
        scene->addItem(rect);

        QGraphicsSimpleTextItem *txt = new QGraphicsSimpleTextItem(QString::fromStdString(e.name));
        txt->setBrush(QBrush(Qt::white));
        QRectF bR = txt->sceneBoundingRect();
        txt->setPos( 25 + computedWidth - bR.width() - 10, y + BAR_HEIGHT/2 - bR.height()/2 );
        scene->addItem(txt);

        // the number label
        txt = new QGraphicsSimpleTextItem(QString::number(e.value));
        txt->setBrush(QBrush(Qt::white));
        bR = txt->sceneBoundingRect();
        txt->setPos( 25 + computedWidth + bR.width() - 10, y + BAR_HEIGHT/2 - bR.height()/2 );
        scene->addItem(txt);

        y += (BAR_HEIGHT*1.2);
    }

}
