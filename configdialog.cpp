#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent ,QString defaultSetting,int_t r,int_t R,int_t x,int_t y,bool directed,bool weighted) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    this->defaultSetting=defaultSetting;
    ui->checkBox_directed->setChecked(directed);
    ui->checkBox_weighted->setChecked(weighted);
    ui->plainTextEdit->setPlainText(defaultSetting);
    ui->spinBox_R->setValue(R);
    ui->spinBox_r->setValue(r);
    ui->spinBox_x->setValue(x);
    ui->spinBox_y->setValue(y);


}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::on_pushButton_clicked()
{
   close();
    // this->setVisible(f;alse);
}




void ConfigDialog::on_checkBox_directed_stateChanged(int arg1)
{

}

void ConfigDialog::on_spinBox_r_valueChanged(int arg1)
{

}

void ConfigDialog::on_spinBox_R_valueChanged(int arg1)
{

}

void ConfigDialog::on_spinBox_x_valueChanged(int arg1)
{

}

void ConfigDialog::on_spinBox_y_valueChanged(int arg1)
{

}

void ConfigDialog::on_plainTextEdit_textChanged()
{

}

void ConfigDialog::on_checkBox_weighted_stateChanged(int arg1)
{

}
int_t ConfigDialog::getr(){
    return ui->spinBox_r->value();
}
int_t ConfigDialog::getR(){
    return ui->spinBox_R->value();
}
int_t ConfigDialog::getRX(){
    return ui->spinBox_x->value();
}
int_t ConfigDialog::getRY(){
    return ui->spinBox_y->value();
}
bool ConfigDialog::isWeighted(){
    return ui->checkBox_weighted->isChecked();
}
bool ConfigDialog::isDirected(){
    return ui->checkBox_directed->isChecked();
}
void ConfigDialog::setr(int_t r){
    ui->spinBox_r->setValue(r);
}
void ConfigDialog::setR(int_t R){
    ui->spinBox_R->setValue(R);
}
void ConfigDialog::setRX(int_t x){
    ui->spinBox_x->setValue(x);
}
void ConfigDialog::setRY(int_t y){
    ui->spinBox_y->setValue(y);
}
void ConfigDialog::setWeighted(bool b){
    ui->checkBox_weighted->setChecked(b);
}
void ConfigDialog::setDirected(bool b){
    ui->checkBox_directed->setCheckable(b);
}
QString ConfigDialog::getSetting(){
    return ui->plainTextEdit->toPlainText();
}
