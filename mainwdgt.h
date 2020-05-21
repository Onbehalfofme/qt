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

public slots:
    void setEdit();
    void setAdd();

private:
    Ui::MainWdgt *ui;
    PressureModel model;
    AddEditPressure addEditPressure;
};

#endif // MAINWDGT_H
