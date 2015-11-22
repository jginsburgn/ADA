#include "tablemodel.h"

TableModel::TableModel(QObject * parent, stringMatrix * newInformation, stringVector newHeaders, int newJump = 0) : QAbstractTableModel(parent){
    information = newInformation;
    headers = newHeaders;
    if (information->size() == 0) jump = newJump;
    else jump = headers.size() - information[0].size();
    ReloadData();
}

int TableModel::rowCount(const QModelIndex & /*parent*/) const {
    return (int)information->size();
}

int TableModel::columnCount(const QModelIndex & /*parent*/) const {
    return headers.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString(information->at(index.row())[index.column()].c_str());
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation /*orientation*/, int role) const {
    if (role == Qt::DisplayRole)
    {
        return QString(headers[section].c_str());
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex & /*index*/) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void TableModel::ReloadData(){
    QModelIndex from = createIndex(0, 0);
    QModelIndex to = information->size() == 0 ? createIndex(0, 0):
              createIndex((int)information->size(), (int)information->at(0).size());
    emit dataChanged(from ,to);
}

