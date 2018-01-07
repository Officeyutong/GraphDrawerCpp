#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QString>
#include "global.h"
#include <QSpinBox>
namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent,QString defaultSetting,int_t r,int_t R,int_t x,int_t y,bool directed,bool weighted);
    ~ConfigDialog();
    QString getSetting();
    int_t getr();
    int_t getR();
    int_t getRX();
    int_t getRY();
    bool isWeighted();
    bool isDirected();
    void setr(int_t r);
    void setR(int_t R);
    void setRX(int_t x);
    void setRY(int_t y);
    void setWeighted(bool b);
    void setDirected(bool b);
private slots:
    void on_pushButton_clicked();

    void on_checkBox_directed_stateChanged(int arg1);

    void on_spinBox_r_valueChanged(int arg1);

    void on_spinBox_R_valueChanged(int arg1);

    void on_spinBox_x_valueChanged(int arg1);

    void on_spinBox_y_valueChanged(int arg1);

    void on_plainTextEdit_textChanged();

    void on_checkBox_weighted_stateChanged(int arg1);

private:
    Ui::ConfigDialog *ui;
    QString defaultSetting;
};

#endif // CONFIGDIALOG_H
