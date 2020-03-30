#ifndef QLISTMODELADAPTER_H
#define QLISTMODELADAPTER_H
#include <QFont>
#include <QColor>
#include <QBrush>
#include <QVariant>
#include <QAbstractTableModel>
#include <QFont>
#include <QAbstractTableModel>
#include "model.h"
#include "container.h"
#include "carta.h"
#include "GUI/cardeditor.h"

class Model;

class QListModelAdapter : public QAbstractTableModel {
private:
    Model* model;
    CardEditor* inserisciCarta;
public:
    QListModelAdapter(QObject* = nullptr, CardEditor* = nullptr);
    ~QListModelAdapter() override;
    Model *getModel() const;

    Qt::ItemFlags flags(const QModelIndex&) const override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    QVariant data(const QModelIndex&, int role = Qt::DisplayRole) const override;
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool matchRegExp(unsigned int, const QRegExp&, const QString&) const;
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;

    void loadFromFile(std::string);
    void fillEditor(const QModelIndex&);
    void saveToFile(std::string) const;
};

#endif // QLISTMODELADAPTER_H
