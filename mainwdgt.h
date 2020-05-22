#ifndef MAINWDGT_H
#define MAINWDGT_H

#include <QWidget>

#include "pressuremodel.h"
#include "addeditpressure.h"
enum COLUMNS
{
 TIME=0, SIS=1,DIS=2
};
namespace Ui {
class MainWdgt;
}

class MainWdgt : public QWidget
{
    Q_OBJECT

public:
    explicit MainWdgt(QWidget *parent = 0);
    ~MainWdgt();

protected slots:
    void editRow();
    void addRow();
private slots:
    void on_deleteRow_clicked();

    void on_saveBtn_clicked();

    void on_loadBtn_clicked();

private:
    Ui::MainWdgt *ui;
    PressureModel model;
    AddEditPressure addEditPressure;
};

#endif // MAINWDGT_H
