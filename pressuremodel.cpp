#include "pressuremodel.h"

PressureModel::PressureModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant PressureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(role)

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
            case 1:
                return QStringLiteral("Время");
            break;
            case 2:
                return QStringLiteral("Сис");
            break;
            case 3:
                return QStringLiteral("Дис");
            break;
        }
    }
}

int PressureModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return pressures.size();
}

int PressureModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
}

QVariant PressureModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(index.row() > rowCount())
        return QVariant();


    QLinkedListIterator<PressureAtTheMoment> it(pressures);
    PressureAtTheMoment rowP = it.next(); //PressureAtTheMoment & че-т не удалось
    int row = index.row();

    while(it.hasNext() || (row!=0))
    {
        row--;
        rowP = it.next();
    }

    switch(index.column())
    {
        case 1:
            if(role == Qt::DisplayRole)
                return rowP.time.toString("hh:mm");
            else
                return rowP.time;
        case 2:
            return rowP.sistolic;
        case 3:
            return rowP.diastolic;
    }
    return QVariant();
}
