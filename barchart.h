#ifndef BARCHART_H
#define BARCHART_H
#include <QGraphicsScene>
#include <map>
#include <QGraphicsSimpleTextItem>

using namespace std;

class BarChart {
private:
    multimap<int,string> theMap;
    string title;
    QGraphicsScene *scene;
public:
    BarChart();
    void setMap(const multimap<int,string> &m);
    void setScene(QGraphicsScene *aScene);
    void setTitle(const string &aTitle);
    void paint();
};

#endif // BARCHART_H
