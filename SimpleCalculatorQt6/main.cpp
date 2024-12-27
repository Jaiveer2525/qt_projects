#include "qt6_calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt6_Calculator w;
    w.show();
    return a.exec();
}
