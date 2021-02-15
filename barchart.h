#ifndef BARCHART_H
#define BARCHART_H
#include <QGraphicsScene>
#include <map>
#include <QGraphicsSimpleTextItem>
#include "bar.h"
using namespace std;

class BarChart {
private:
    multimap<int,string> theMap;
    vector<Bar> theBars;
    string title;
    string xAxisLabel;
    string dataSource;
    string caption;
    QGraphicsScene *scene;
public:
    BarChart();
    BarChart(string aTitle, string aXLabel, string aSource);
    void setCaption(string aCaption);
    void add(string name, int value, string category);
    void setMap(const multimap<int,string> &m);
    void reset();
    void setBars(const vector<Bar> &b);
    void setScene(QGraphicsScene *aScene);
    void setTitle(const string &aTitle);
    void paint();
};

#endif // BARCHART_H
