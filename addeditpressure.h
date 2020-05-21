#ifndef ADDEDITPRESSURE_H
#define ADDEDITPRESSURE_H

#include <QDialog>

#include "pressuremodel.h"

namespace Ui {
class AddEditPressure;
}

class AddEditPressure : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditPressure(QWidget *parent = 0);
    ~AddEditPressure();

    void fillByObj(const PressureModel::PressureAtTheMoment* obj);
public slots:
    void setAdd();
    void setEdit();
    void cancel();
    void ok();
private:
    Ui::AddEditPressure *ui;
};

#endif // ADDEDITPRESSURE_H
