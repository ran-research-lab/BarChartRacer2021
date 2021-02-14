#ifndef BARCHARTRACER_H
#define BARCHARTRACER_H

#include <QTimer>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "barchart.h"
class BarChartRacer : public QMainWindow
{
    Q_OBJECT
private:
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    BarChart *barChart;
    vector <string> titles = {"1990", "1991", "1992"};
    vector< multimap<int,string> > allData =
    { {{100,"uno"},{100,"dos"}},
      {{200,"tres"},{150,"cuatro"}},
      {{130,"tres"},{250,"cuatro"},{150,"seis"}}
    };
    int idx = 0;
public:
    BarChartRacer(QWidget *parent = nullptr);
    ~BarChartRacer();
    void paint();
public slots:
    void advance();
};
#endif // BARCHARTRACER_H
