#include "addeditpressure.h"
#include "ui_addeditpressure.h"

AddEditPressure::AddEditPressure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPressure)
{
    ui->setupUi(this);
    connect(ui->okBtn, &QPushButton::clicked, this, &AddEditPressure::ok);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &AddEditPressure::cancel);
}

AddEditPressure::~AddEditPressure()
{
    delete ui;
}

void AddEditPressure::fillByObj(const PressureModel::PressureAtTheMoment* obj)
{
    ui->sisP->setText(QString::number(obj->sistolic));
    ui->diasP->setText(QString::number(obj->diastolic));
    ui->timeCtrl->setTime(QTime(obj->hour, obj->minute));
}

void AddEditPressure::setAdd(){
    ui->sisP->clear();
    ui->diasP->clear();
    ui->timeCtrl->clear();
    show();
}
void AddEditPressure::setEdit(){
    ui->sisP->setText("aaaa");
    ui->diasP->setText("aaaa");
    ui->timeCtrl->setDate(QDate::fromString("10:00", "hh:mm"));
    show();
}

void AddEditPressure::cancel(){
    hide();
}
void AddEditPressure::ok(){
    hide();
}
