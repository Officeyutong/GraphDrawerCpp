#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "configdialog.h"
#include "graphdrawer.h"
#include "helpdialog.h"
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event){
        if(event->key()==Qt::Key_Shift){
            shiftPressed=true;
        }
    }
    void keyReleaseEvent(QKeyEvent *event){
        if(event->key()==Qt::Key_Shift){
            shiftPressed=false;
        }
    }
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    ConfigDialog *dialog;
    HelpDialog * help;
    QPixmap graph;
    bool shiftPressed=false;



};

#endif // MAINWINDOW_H
