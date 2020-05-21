#ifndef MAINWDGT_H
#define MAINWDGT_H

#include <QWidget>

#include "pressuremodel.h"
#include "addeditpressure.h"

namespace Ui {
class MainWdgt;
}

class MainWdgt : public QWidget
{
    Q_OBJECT

public:
    explicit MainWdgt(QWidget *parent = 0);
    ~MainWdgt();



private:
    Ui::MainWdgt *ui;
    PressureModel model;
    AddEditPressure addEditPressure;
};

#endif // MAINWDGT_H
