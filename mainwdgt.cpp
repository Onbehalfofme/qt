#include "mainwdgt.h"
#include "ui_mainwdgt.h"
#include "addeditpressure.h"


MainWdgt::MainWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdgt)
{
    ui->setupUi(this);

    ui->tblViewer->setModel(&model);
    connect(ui->addRow, &QPushButton::clicked, this, &MainWdgt::setAdd);
    connect(ui->editRow, &QPushButton::clicked, this, &MainWdgt::setEdit);
}

MainWdgt::~MainWdgt()
{
    delete ui;
}

void MainWdgt::setAdd(){
    addEditPressure.setAdd();
}
void MainWdgt::setEdit(){

    model.index();

}
