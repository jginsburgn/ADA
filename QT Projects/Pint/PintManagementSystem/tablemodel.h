#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QTableView>
#include "pintgd.h"

class TableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    stringMatrix * information;
    stringVector headers;
    int jump;
    QTableView * myTable;

public:
    TableModel(QObject * parent, QTableView * table, stringMatrix * newInformation, stringVector newHeaders, int newJump = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;
    void ReloadData();

public slots:
    void CellClicked(const QModelIndex & cell);
    void CellDoubleClicked(const QModelIndex & cell);

signals:
    void RowClicked(const int row);
    void RowDoubleClicked(const int row);
};

#endif // TABLEMODEL_H
