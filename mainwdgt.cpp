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
}

MainWdgt::~MainWdgt()
{
    delete ui;
}
