#include "qfilterproxymodel.h"

QFilterProxyModel::QFilterProxyModel(QObject* parent, const QComboBox* c, CardEditor* e) : QSortFilterProxyModel (parent), searchAttribute(c), inserisciCarta(e){}

bool QFilterProxyModel::insertRows(int begin, int count, const QModelIndex& parent) {
    bool result = sourceModel()->insertRows(begin, count, parent);
    invalidateFilter();
    return result;
}

void QFilterProxyModel::removeResults() {
    while(rowCount()){
        removeRows(0,1);
    }
}

bool QFilterProxyModel::filterAcceptsRow(int row_source, const QModelIndex&) const {
    std::string s=searchAttribute->currentText().toUtf8().constData();
    return static_cast<QListModelAdapter*>(sourceModel())->matchRegExp(static_cast<unsigned int>(row_source),
                                                                       filterRegExp(),
                                                                       searchAttribute->currentText());
}

void QFilterProxyModel::fillEditor(const QModelIndex& index) const{
    QModelIndex index_source = mapToSource(index);
    static_cast<QListModelAdapter*>(sourceModel())->fillEditor(index_source);
}
