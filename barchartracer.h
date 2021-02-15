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
    vector <string> captions = {"1990", "1991", "1992"};
    vector< vector< Bar> > allData =
    { {Bar("gato", 100,"uno"),Bar("gato", 100,"dos")} ,
      {Bar{"gato", 200,"tres"},Bar{"gato", 150,"cuatro"}},
      {Bar{"gato", 130,"tres"},Bar{"gato", 250,"cuatro"},Bar{"gato", 150,"seis"}}
    };
    int idx = 0;
public:
    BarChartRacer(QWidget *parent = nullptr);
    ~BarChartRacer();
//    void paint();
public slots:
    void advance();
};
#endif // BARCHARTRACER_H
