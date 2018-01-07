#include "graphdrawer.h"

void GraphDrawer::draw(){

    double deg=-PI*2/vertexes.size();
    int_t i=0;
    for(int_t v:vertexes){
     //   std::cout<<"drawing vertex "<<v<<endl;
        double currDeg=deg*(i--);
        QPoint center(dialog->getRX(),dialog->getRY());
        QPoint p=getPointAtCircle(center,dialog->getR(),currDeg);
        drawCircleAt(painter,p,dialog->getr(),QString::number(v));
        points[v]=p;
    }
    for(Path p:edges){
     //   std::cout<<"drawing path from "<<p.from<<" to "<<p.to<<" weight"<<p.weight<<endl;
        QPoint p1=points[p.from];
        QPoint p2=points[p.to];
        double slope=getSlope(p1,p2);
        int_t r=dialog->getr();
        if(slope<0) slope+=PI;
        if(slope>PI) slope-=PI;
        if(slope>PI/2) slope=PI-slope;
        if(p1.x()<p2.x()){
            p1.rx()+=r*cos(slope);
            p2.rx()-=r*cos(slope);
        }
        if(p1.x()>p2.x()){
            p1.rx()-=r*cos(slope);
            p2.rx()+=r*cos(slope);
        }
        if(p1.y()<p2.y()){
            p1.ry()+=r*sin(slope);
            p2.ry()-=r*sin(slope);
        }
        if(p1.y()>p2.y()){
            p1.ry()-=r*sin(slope);
            p2.ry()+=r*sin(slope);
        }
        painter->drawLine(p1,p2);
        if(dialog->isWeighted()){

            painter->eraseRect((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2 - r, r * 2, r);
            painter->drawText( (p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2,QString::number(p.weight));

        }
        if(dialog->isDirected()){
            drawTarget(painter,p2);
        }

    }
}
void GraphDrawer::parse(){
    QString str=dialog->getSetting();
    str+=" \n";
    QStringList splits=str.split("\n");
    for(QString& x:splits){
        QString trimed=x.trimmed();
        if(trimed=="") continue;
        if(trimed.startsWith("//")) continue;
        Path path=Path(trimed);
        edges.insert(path);
        vertexes.insert(path.from);
        vertexes.insert(path.to);
    }
}
GraphDrawer::GraphDrawer(ConfigDialog *dialog,QPainter * painter){
    this->dialog=dialog;
    this->painter=painter;
    parse();

}
