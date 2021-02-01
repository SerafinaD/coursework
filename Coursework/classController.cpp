#include "classController.hpp"

Controller::Controller(QObject *parent, Paint_Trd *p_t) : QObject(parent), Paint_Thr(p_t)
{

}

void Controller::startCalc(Aim *a, Rocket *r, double t)
{
    if (calcTrd.data())
       {
           calcTrd->calcStop();
           calcTrd->terminate();
           calcTrd.reset();
           return;
       }
    calcTrd = QSharedPointer<Calc_Trd>::create(a, r, t);
    calcTrd->start(QThread::NormalPriority);
    connect(calcTrd.data(), SIGNAL(stopedThread()), this, SLOT(deleteThread()));
    connect(calcTrd.data(), SIGNAL(paintThread(int, int, int, int)), Paint_Thr, SLOT(paint(int, int, int, int)));
    connect(this, SIGNAL(boom()), Paint_Thr, SLOT(boom()));
}

Controller::~Controller()
{
   if (calcTrd != nullptr)       // При завершении нужно остановить поток,
                                    // если он существует
   {
       if (calcTrd->isRunning()) // Проверяем, работает ли поток
       {
           calcTrd->calcStop();  // Меняем флаг для завершения всех циклов
                                    // потока
           calcTrd->terminate(); // Ожидаем завершения потока
       }
       calcTrd.reset();          // Сбрасываем поток, вызывая деструктор
   }
}

void Controller::deleteThread()
{
    emit boom();
    calcTrd.reset();
}
