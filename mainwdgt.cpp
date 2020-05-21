#include "mainwdgt.h"
#include "ui_mainwdgt.h"


MainWdgt::MainWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdgt)
{
    ui->setupUi(this);

    ui->tblViewer->setModel(&model);
}

MainWdgt::~MainWdgt()
{
    delete ui;
}
