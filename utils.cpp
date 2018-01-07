#include <utils.h>

QPoint getPointAtCircle(QPoint center,int_t r,double angle){
    return QPoint(floor(center.x()+r*cos(angle)),floor(center.y()+r*sin(angle)));
}
void drawCircleAt(QPainter* painter,QPoint point,int_t r,QString str){
    painter->drawEllipse(point,r,r);
    painter->drawText(QPoint(point.x()-r/2,point.y()+r/2),str);
}
void drawTarget(QPainter * painter,QPoint center){
    painter->fillRect(center.x()-2,center.y()-2,4,4,QColor(255,0,0));
}
double getSlope(QPoint p1,QPoint p2){
    return atan2(p2.y()-p1.y(),p2.x()-p1.x());
}
