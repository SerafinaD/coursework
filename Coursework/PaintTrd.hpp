#ifndef PAINTTRD_HPP
#define PAINTTRD_HPP

#include <QObject>
#include <QThread>



class Paint_Trd: public QThread
{
    Q_OBJECT
private:
bool isWork;
public:
    Paint_Trd(QObject *parent);
protected:
    void run();
private slots:
    void paint(int xt, int yt, int xr, int yr);
    void boom();
};
#endif
