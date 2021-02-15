#include "barchartracer.h"
#include <iostream>
#include <QGraphicsRectItem>
using namespace std;

BarChartRacer::BarChartRacer(QWidget *parent)
    : QMainWindow(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    timer->start(500);

    scene = new QGraphicsScene(parent);
    view  = new QGraphicsView(scene);

    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,600, 400);
    scene->addItem(rect);

    barChart = new BarChart("Un Titulo", "Un Label", "Un data source");
    barChart->setScene(scene);

    view->show();
}

BarChartRacer::~BarChartRacer() {
    delete timer;
    delete scene;
    delete view;
}

void BarChartRacer::advance() {

    barChart->reset();
    for(const auto &e: allData[idx])
        barChart->add(e.name,e.value,e.category);

    barChart->setCaption(captions[idx]);
    barChart->paint();

    idx = (idx + 1) % allData.size();
}


