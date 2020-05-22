#ifndef ADDEDITPRESSURE_H
#define ADDEDITPRESSURE_H

#include <QDialog>
#include <QTime>

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

    enum MODE{
        ADD,
        EDIT
    };
    void fillByObj(const PressureModel::PressureAtTheMoment* obj);
    void setEditingRow(int row);
    void setMode(const MODE &value);

public slots:
    void setAdd();

public slots:
    void cancel();
    void ok();
signals:
    void editObj(int row, QTime time, int sistolic, int diastolic);
    void addObj(int row,QTime time, int sistolic, int diastolic);
private:
    Ui::AddEditPressure *ui;
    int editingRow;
    MODE mode;
};

#endif // ADDEDITPRESSURE_H
