#include "barchartracer.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    BarChartRacer b;
    b.paint();
    return a.exec();
}
