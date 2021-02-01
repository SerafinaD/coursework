#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QObject>
#include <QSharedPointer>
#include <QApplication>
#include "CalcTrd.hpp"
#include "PaintTrd.hpp"

class Controller : public QObject
{
   Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, Paint_Trd *p_t = nullptr);
    void startCalc(Aim *a, Rocket *r, double t);
    ~Controller();
private:
   QSharedPointer<Calc_Trd>calcTrd;
   Paint_Trd *Paint_Thr;

public slots:
   void deleteThread();

signals:
    void boom();
};

#endif
