#ifndef MAINWDGT_H
#define MAINWDGT_H

#include <QWidget>

#include "pressuremodel.h"

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
};

#endif // MAINWDGT_H
