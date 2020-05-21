#ifndef ADDEDITPRESSURE_H
#define ADDEDITPRESSURE_H

#include <QDialog>

namespace Ui {
class AddEditPressure;
}

class AddEditPressure : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditPressure(QWidget *parent = 0);
    ~AddEditPressure();

public slots:
    void setAdd();
private:
    Ui::AddEditPressure *ui;
};

#endif // ADDEDITPRESSURE_H
