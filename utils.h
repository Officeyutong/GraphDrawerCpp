#ifndef UTILS_H
#define UTILS_H

#include <QPoint>
#include <QPainter>
#include "global.h"

    QPoint getPointAtCircle(QPoint center,int_t r,double angle);
    void drawCircleAt(QPainter* painter,QPoint point,int_t r,QString str);
    void drawTarget(QPainter * painter,QPoint center);
    double getSlope(QPoint p1,QPoint p2);

#endif // UTILS_H
