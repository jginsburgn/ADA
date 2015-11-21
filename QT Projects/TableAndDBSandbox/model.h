#ifndef MODEL_H
#define MODEL_H

#include "Helper.h"
#include "GeneralQt.h"
#include <pqxx/pqxx>
#include <QAbstractTableModel>

class Model : public QAbstractTableModel {
    Q_OBJECT

private:
    pqxx::result result;

public:
    Model(QObject * parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole)
        Q_DECL_OVERRIDE;

    void ReloadData();
};

#endif // MODEL_H
