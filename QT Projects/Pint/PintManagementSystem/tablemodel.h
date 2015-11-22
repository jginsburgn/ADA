#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "pintgd.h"

class TableModel : public QAbstractTableModel{
    Q_OBJECT

private:
    stringMatrix * information;
    stringVector headers;
    int jump;

public:
    TableModel(QObject * parent, stringMatrix * newInformation, stringVector newHeaders, int newJump);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;

    void ReloadData();

signals:

};

#endif // TABLEMODEL_H
