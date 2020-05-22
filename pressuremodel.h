#ifndef PRESSUREMODEL_H
#define PRESSUREMODEL_H

#include <QAbstractTableModel>
#include <QLinkedList>
#include <QTime>


class PressureModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PressureModel(QObject *parent = nullptr);
    ~PressureModel();

    struct PressureAtTheMoment
    {
        int hour;
        int minute;
        int sistolic;
        int diastolic;
    };
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;

    bool saveToFile(QString path);
    bool loadFromFile(QString path);
    bool getFromDb();

    bool appendRow(QTime time, int sistolic, int diastolic);

    const PressureAtTheMoment * getObjAtRow(int row) const;
    void clear();
public slots:
    void editRow(int row, QTime time, int sistolic, int diastolic);
    void addRow(int row, QTime time, int sistolic, int diastolic);
private:
    QLinkedList<PressureAtTheMoment*> pressures;
};

#endif // PRESSUREMODEL_H
