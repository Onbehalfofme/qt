#include "pressuremodel.h"

#include <QFile>
#include <QDebug>

PressureModel::PressureModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

PressureModel::~PressureModel()
{
    pressures.clear();
}

QVariant PressureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(role)

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
            case 0:
                return QStringLiteral("Время");
            break;
            case 1:
                return QStringLiteral("Сис");
            break;
            case 2:
                return QStringLiteral("Дис");
            break;
        }
    }
    return QVariant();
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

    auto it = pressures.begin();
    it = it + index.row();
    PressureAtTheMoment * rowP = *it;

    if(role == Qt::DisplayRole)
        switch(index.column())
        {
        case 0:
            return QTime(rowP->hour, rowP->minute).toString("hh:mm");
        case 1:
            return rowP->sistolic;
        case 2:
            return rowP->diastolic;
        }
    return QVariant();
}

bool PressureModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role)
    QLinkedList<PressureAtTheMoment*>::iterator it = pressures.begin();
    it = it + index.row();
    PressureAtTheMoment * newP = *it;

    switch(index.column())
    {
        case 1:
            newP->hour = value.toTime().hour();
            newP->minute = value.toTime().minute();
        break;
        case 2:
            newP->sistolic = value.toInt();
        break;
        case 3:
            newP->diastolic = value.toInt();
        break;
        default:
         return false;
    }
    emit dataChanged(index,index);
    return true;
}

bool PressureModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count);

    PressureAtTheMoment * newP = new PressureAtTheMoment;

    QLinkedList<PressureAtTheMoment*>::iterator it = pressures.begin();
    it = it+row;
    pressures.insert(it, newP);


    endInsertRows();
}

bool PressureModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent,row,row+count-1);

    QLinkedList<PressureAtTheMoment*>::iterator it = pressures.begin();
    it = it+row;
    pressures.erase(it);
    endRemoveRows();
}

bool PressureModel::saveToFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        unsigned char HEADER[4] = {187,170,221,221};
        file.write((char*)HEADER,4);
        QLinkedListIterator<PressureAtTheMoment*> it(pressures);
        PressureAtTheMoment * newP = nullptr;
        while(it.hasNext())
        {
            newP=it.next();
            file.write((char*)newP, sizeof(PressureAtTheMoment));
        }
        return true;
    }
    else
        return false;
}

bool PressureModel::loadFromFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        clear();
        unsigned char HEADER[4] = {187,170,221,221};//0xBBAADDDD
        unsigned char FILE_HEADER[4];
        file.read((char*)FILE_HEADER,4);
        for(int i=0;i<4;i++)
        {
            if(FILE_HEADER[i] != HEADER[i])
            {
                qDebug()<<"wrong file header";
                return false;
            }
        }
        while(!file.atEnd())
        {
            PressureAtTheMoment * newP = new PressureAtTheMoment;
            file.read((char*)newP, sizeof(PressureAtTheMoment));
            beginInsertRows(QModelIndex(),rowCount(),rowCount());
                pressures.append(newP);
            endInsertRows();
        }
        return true;
    }
    else
        return false;
}

void PressureModel::addRow(int row, QTime time, int sistolic, int diastolic)
{
    beginInsertRows(QModelIndex(),row,row);

    PressureAtTheMoment * newP = new PressureAtTheMoment;
    newP->hour = time.hour();
    newP->minute = time.minute();
    newP->sistolic = sistolic;
    newP->diastolic = diastolic;

    QLinkedList<PressureAtTheMoment*>::iterator it = pressures.begin();
    it = it+row+1;
    pressures.insert(it, newP);

    endInsertRows();

}

bool PressureModel::appendRow(QTime time, int sistolic, int diastolic)
{
    addRow(rowCount(), time, sistolic, diastolic);
}

const PressureModel::PressureAtTheMoment *PressureModel::getObjAtRow(int row) const
{
    auto it = pressures.begin();
    it=it+row;
    return *it;
}

void PressureModel::clear()
{
    beginRemoveRows(QModelIndex(),0,rowCount()-1);
        pressures.clear();
    endRemoveRows();
}

void PressureModel::editRow(int row, QTime time, int sistolic, int diastolic)
{
    auto it = pressures.begin();
    it=it+row;
    (*it)->hour = time.hour();
    (*it)->minute = time.minute();
    (*it)->sistolic = sistolic;
    (*it)->diastolic = diastolic;
    emit dataChanged(index(row,0),index(row,2));
}




