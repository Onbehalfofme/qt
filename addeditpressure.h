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
    void setAdd();
    void setEdit();

public slots:
    void cancel();
    void ok();
private:
    Ui::AddEditPressure *ui;
};

#endif // ADDEDITPRESSURE_H
