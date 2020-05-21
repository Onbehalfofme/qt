#include "addeditpressure.h"
#include "ui_addeditpressure.h"

AddEditPressure::AddEditPressure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPressure)
{
    ui->setupUi(this);
}

AddEditPressure::~AddEditPressure()
{
    delete ui;
}

void AddEditPressure::setAdd(){
    ui->sisP->clear();
    ui->diasP->clear();
    ui->timeCtrl->clear();
    show();
}