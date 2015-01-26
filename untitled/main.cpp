#include "testgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestGame w;
    w.resize(800,600);
    w.setMaximumSize(QSize(800,600));
    w.setMinimumSize(QSize(800,600));
    w.setAnimating(true);
    w.show();

    return a.exec();
}
