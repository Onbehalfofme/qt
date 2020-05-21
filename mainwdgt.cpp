#include "mainwdgt.h"
#include "ui_mainwdgt.h"


MainWdgt::MainWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdgt)
{
    ui->setupUi(this);

    ui->tblViewer->setModel(&model);
    ui->tblViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblViewer->setSelectionBehavior(QAbstractItemView::SelectRows);

    addEditPressure.setModal(true);

    connect(ui->addRow, &QPushButton::clicked, &addEditPressure, &AddEditPressure::setAdd);
    connect(ui->editRow, &QPushButton::clicked, this, &MainWdgt::editRow);

    model.addRow(0,QTime(00,44),120,70);
    model.addRow(1,QTime(02,24),130,10);
    model.addRow(2,QTime(20,44),160,30);
}

MainWdgt::~MainWdgt()
{
    delete ui;
}

void MainWdgt::editRow()
{
    if(!ui->tblViewer->selectionModel()->selectedRows().isEmpty())
    {
        int row = ui->tblViewer->selectionModel()->selectedRows().last().row();
        addEditPressure.fillByObj(model.getObjAtRow(row));
        addEditPressure.show();
    }

}
