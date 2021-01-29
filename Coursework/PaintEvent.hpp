#ifndef PAINTEVENT_HPP
#define PAINTEVENT_HPP

#include <QEvent>
#include <QPoint>

class PaintEvent : public QEvent {
private:
    QPoint aim;
    QPoint rocket;

public:
    enum {PaintType = User + 1};

    PaintEvent() : QEvent((Type)PaintType)
    {
    }

    void setPoints(int xt, int yt, int xr, int yr) 
    {
        aim.setX(xt);
        aim.setY(yt);
        rocket.setX(xr);
        rocket.setY(yr);
    }
 
    QPoint aim_pos() const
    {
        return aim;
    }
    
    QPoint rocket_pos() const
    {
        return rocket;
    }
};

#endif
