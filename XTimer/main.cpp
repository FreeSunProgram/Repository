#include <QCoreApplication>
#include <iostream>
#include "xtimer.h"

void functionT()
{
    static XTimer timer(std::bind(functionT)/*, XTimer::CONTINUDE*/);

    timer.start(2000);

    std::cout << "TIME_OUT !" << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    functionT();

//    XTimer timer(std::bind(functionT), XTimer::CONTINUDE);

//    timer.start(2000);

    std::cout << "start !" << std::endl;

    return a.exec();
}
