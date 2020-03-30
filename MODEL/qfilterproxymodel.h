#ifndef QFILTERPROXYMODEL_H
#define QFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>
#include <QComboBox>
#include "qlistmodeladapter.h"
#include "GUI/cardeditor.h"

class QFilterProxyModel : public QSortFilterProxyModel {
private:
    const QComboBox* searchAttribute;
    CardEditor* inserisciCarta;
public:
    QFilterProxyModel( QObject* = nullptr, const QComboBox* = nullptr, CardEditor* = nullptr);
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    void removeResults() ;
    void fillEditor(const QModelIndex&) const;
protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};
#endif // QFILTERPROXYMODEL_H
