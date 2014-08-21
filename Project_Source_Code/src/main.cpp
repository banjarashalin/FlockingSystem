#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int numBoids;
    if(argc ==1)
    {
            numBoids=50;
    }
    else
    {
                    numBoids=atoi(argv[1]);
    }
    MainWindow w(numBoids);
    w.show();

    return a.exec();
}
