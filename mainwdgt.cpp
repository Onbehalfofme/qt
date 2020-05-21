#include "mainwdgt.h"
#include "ui_mainwdgt.h"
#include "addeditpressure.h"


MainWdgt::MainWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdgt)
{
    ui->setupUi(this);

    ui->tblViewer->setModel(&model);
    connect(ui->addRow, &QPushButton::clicked, this, &AddEditPressure::setAdd);
}

MainWdgt::~MainWdgt()
{
    delete ui;
}
