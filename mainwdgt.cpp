#include "mainwdgt.h"
#include "ui_mainwdgt.h"


MainWdgt::MainWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdgt)
{
    ui->setupUi(this);

    ui->tblViewer->setModel(&model);
    connect(ui->addRow, &QPushButton::clicked, &addEditPressure, &AddEditPressure::setAdd);
    connect(ui->editRow, &QPushButton::clicked, &addEditPressure, &AddEditPressure::setEdit);

    model.addRow(0,QTime(00,44),120,70);
    model.addRow(1,QTime(00,44),120,70);
    model.addRow(2,QTime(00,44),120,70);
}

MainWdgt::~MainWdgt()
{
    delete ui;
}
