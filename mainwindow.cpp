#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog=new ConfigDialog(this,tr("1 2\n2 3\n3 4\n4 1\n"),10,100,this->width()/2,this->height()/2,true,false);
    help=new HelpDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    dialog->show();
    //dialog->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->setVisible(false);
    this->repaint();
    QPixmap pix,bmp;
    pix=bmp.grabWindow(this->winId());
    QString fileName=QFileDialog::getSaveFileName(this,"选择保存位置..",QApplication::desktopFileName(),"BMP图片(*.bmp)|*.bmp");
    pix.save(fileName);
    ui->widget->setVisible(true);
}
void MainWindow::paintEvent(QPaintEvent *event){


        QPainter painter(this);
        GraphDrawer drawer=GraphDrawer(dialog,&painter);
        drawer.draw();


}

void MainWindow::on_pushButton_4_clicked()
{
    help->show();
}

void MainWindow::resizeEvent(QResizeEvent *event){
    dialog->setRX(this->width()/2);
    dialog->setRY(this->height()/2);

}

void MainWindow::on_pushButton_3_clicked()
{

}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        if(shiftPressed){
            dialog->setRX(event->x());
            dialog->setRY(event->y());
            repaint();
        }
    }
}
