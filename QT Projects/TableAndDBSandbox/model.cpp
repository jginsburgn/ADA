#include "model.h"

Model::Model(QObject * parent) : QAbstractTableModel(parent) {
    ReloadData();
}

int Model::rowCount(const QModelIndex & /*parent*/) const {
    return result.size();
}

int Model::columnCount(const QModelIndex & /*parent*/) const {
    return result.columns();
}

QVariant Model::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString(result[index.row()][index.column()].as<std::string>().c_str());
    }
    return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QString(result.column_name(section));
    }
    return QVariant();
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int /*role*/) {
    std::cout << "Cell's info changed... Row: " << index.row() << ", Column: " << index.column() << std::endl;
    emit dataChanged(QModelIndex(index), QModelIndex(index));
    return true;
}

Qt::ItemFlags Model::flags(const QModelIndex & /*index*/) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void Model::ReloadData() {
    pqxx::connection dbConnection("dbname=test user=test host=localhost password=123456");
    pqxx::work transaction(dbConnection);
    result = transaction.exec("select id, name, salary from employee");
}

