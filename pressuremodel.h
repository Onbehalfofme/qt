#ifndef PRESSUREMODEL_H
#define PRESSUREMODEL_H

#include <QAbstractTableModel>
#include <QLinkedList>
#include <QTime>

class PressureModel : public QAbstractTableModel
{
    Q_OBJECT

    struct PressureAtTheMoment
    {
        QTime time;
        int sistolic;
        int diastolic;
    };

public:
    explicit PressureModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


private:
    QLinkedList<PressureAtTheMoment> pressures;
};

#endif // PRESSUREMODEL_H
