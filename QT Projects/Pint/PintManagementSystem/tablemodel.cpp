#include "tablemodel.h"

TableModel::TableModel(QObject * parent, QTableView * table, stringMatrix * newInformation, stringVector newHeaders, int newJump) : QAbstractTableModel(parent){
    information = newInformation;
    headers = newHeaders;
    if (information->size() == 0 || newJump != 0) jump = newJump;
    else jump = headers.size() - information[0].size();
    ReloadData();
    this->myTable = table;
    myTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(table,SIGNAL(clicked(QModelIndex)),this,SLOT(CellClicked(QModelIndex)));
    connect(table,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(CellDoubleClicked(QModelIndex)));
}

int TableModel::rowCount(const QModelIndex & /*parent*/) const {
    return (int)information->size();
}

int TableModel::columnCount(const QModelIndex & /*parent*/) const {
    return headers.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString(information->at(index.row())[index.column() + jump].c_str());
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return QString(headers[section].c_str());
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex & /*index*/) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void TableModel::ReloadData(){
    beginResetModel();
    endResetModel();
    return;
}

void TableModel::CellClicked(const QModelIndex & cell) {
    emit RowClicked(cell.row());
}

void TableModel::CellDoubleClicked(const QModelIndex & cell){
    emit RowDoubleClicked(cell.row());
}
