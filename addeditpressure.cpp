#include "addeditpressure.h"
#include "ui_addeditpressure.h"

AddEditPressure::AddEditPressure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPressure)
{
    ui->setupUi(this);
    connect(ui->okBtn, &QPushButton::clicked, this, &AddEditPressure::ok);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &AddEditPressure::cancel);
    editingRow = -1;
    mode = MODE::ADD;
}

AddEditPressure::~AddEditPressure()
{
    delete ui;
}

void AddEditPressure::fillByObj(const PressureModel::PressureAtTheMoment* obj)
{
    ui->sisP->setValue(obj->sistolic);
    ui->diasP->setValue(obj->diastolic);
    ui->timeCtrl->setTime(QTime(obj->hour, obj->minute));
}

void AddEditPressure::setEditingRow(int row)
{
    editingRow = row;
}

void AddEditPressure::setAdd(){
    ui->sisP->setValue(110);
    ui->diasP->setValue(70);
    ui->timeCtrl->setTime(QTime::currentTime());
    mode = MODE::ADD;
    show();
}

void AddEditPressure::cancel(){
    hide();
}
void AddEditPressure::ok(){
    switch (mode) {
    case MODE::ADD:
        emit addObj(editingRow,ui->timeCtrl->time(), ui->sisP->value(), ui->diasP->value());
        break;
    case MODE::EDIT:
        emit editObj(editingRow, ui->timeCtrl->time(), ui->sisP->value(), ui->diasP->value());
        break;
    }
    hide();
}

void AddEditPressure::setMode(const MODE &value)
{
    mode = value;
}
