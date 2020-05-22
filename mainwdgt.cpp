#include "mainwdgt.h"
#include "ui_mainwdgt.h"

#include <QFileDialog>


MainWdgt::MainWdgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdgt)
{
    ui->setupUi(this);

    ui->tblViewer->setModel(&model);
    ui->tblViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblViewer->setSelectionBehavior(QAbstractItemView::SelectRows);

    addEditPressure.setModal(true);

    connect(ui->addRow, &QPushButton::clicked, this, &MainWdgt::addRow);
    connect(ui->editRow, &QPushButton::clicked, this, &MainWdgt::editRow);

    connect(&addEditPressure, &AddEditPressure::editObj, &model, &PressureModel::editRow);
    connect(&addEditPressure, &AddEditPressure::addObj, &model, &PressureModel::addRow);

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
        addEditPressure.setEditingRow(row);
        addEditPressure.fillByObj(model.getObjAtRow(row));
        addEditPressure.setMode(AddEditPressure::MODE::EDIT);
        addEditPressure.show();
    }

}

void MainWdgt::addRow()
{
    int row = 0;
    if(!ui->tblViewer->selectionModel()->selectedRows().isEmpty())
    {
        row = ui->tblViewer->selectionModel()->selectedRows().last().row();
    }
    addEditPressure.setEditingRow(row);
    addEditPressure.setAdd();
}

void MainWdgt::on_deleteRow_clicked()
{
    if(!ui->tblViewer->selectionModel()->selectedRows().isEmpty())
    {
        int row = ui->tblViewer->selectionModel()->selectedRows().last().row();
        model.removeRow(row);
    }
}

void MainWdgt::on_saveBtn_clicked()
{
    QString _fileName = QFileDialog::getSaveFileName(0, tr("Сохранить таблицу как"), QString(), tr("Таблица (*.p)"));
    model.saveToFile(_fileName);
}

void MainWdgt::on_loadBtn_clicked()
{
    QString _fileName = QFileDialog::getOpenFileName(0, tr("Загрузить таблицу"), QString(), tr("Таблица (*.p)"));
    model.loadFromFile(_fileName);
}
