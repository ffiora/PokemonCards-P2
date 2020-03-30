#include "qlistmodeladapter.h"

QListModelAdapter::QListModelAdapter(QObject* parent,CardEditor* e) :
    QAbstractTableModel(parent),
    model(new Model()),
    inserisciCarta(e) {}

QListModelAdapter::~QListModelAdapter() {
    delete model;
}
Model *QListModelAdapter::getModel() const
{
    return model;
}

int QListModelAdapter::rowCount(const QModelIndex &) const {
    return static_cast<int>(model->count());
}
int QListModelAdapter::columnCount(const QModelIndex &) const {
    return 6;
}
QVariant QListModelAdapter::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if(role==Qt::FontRole)
    {
        return QFont("Arial", 24, QFont::Bold);
    }
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Posseduta");
        case 1:
            return QString("Nome");
        case 2:
            return QString("Numero");
        case 3:
            return QString("Rarità");
        case 4:
            return QString("Espansione");
        case 5:
            return QString("Serie");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant QListModelAdapter::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= static_cast<int>(model->count()) || index.row()<0)
        return QVariant();
    switch(role){
        case Qt::BackgroundColorRole:
        {
            if(dynamic_cast<Pokemon*>(&*model->getMazzo()[index.row()])) return QVariant(QBrush(QColor(224,255,255)));
            if (dynamic_cast<Allenatore*>(&*model->getMazzo()[index.row()])) return QVariant(QBrush(QColor(255,228,225)));
            if (dynamic_cast<Energia*>(&*model->getMazzo()[index.row()])) return QVariant(QBrush(QColor(255,250,205)));
            return QVariant(QBrush(QColor(Qt::gray)));
        }
        case Qt::TextAlignmentRole:
            return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
        case Qt::EditRole:
        case Qt::DisplayRole:
        {
            switch(index.column())
            {
            case 0:
                return QString::fromStdString(model->getMazzo()[index.row()]->getPosseduta()==true?"SI":"NO");
            case 1:
                return QString::fromStdString(model->getMazzo()[index.row()]->getNome());
            case 2:
                return QString::fromStdString(model->getMazzo()[index.row()]->getNumero());
            case 3:
                return QString::fromStdString(model->getMazzo()[index.row()]->getRarita());
            case 4:
                return QString::fromStdString(model->getMazzo()[index.row()]->getEspansione());
            case 5:
                return QString::fromStdString(model->getMazzo()[index.row()]->getSerie());
            default:
                return QVariant();
        }
    }
    }
    return QVariant();
}

bool QListModelAdapter::removeRows(int begin, int count, const QModelIndex& parent) {
    beginRemoveRows(parent, begin, begin + count - 1);
    model->remove(static_cast<unsigned int>(begin));
    endRemoveRows();
    return true;
}

Qt::ItemFlags QListModelAdapter::flags(const QModelIndex& index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index);
}

bool QListModelAdapter::matchRegExp(unsigned int r, const QRegExp& s, const QString& a) const{
    if(a=="Posseduta")
        return QString::fromStdString(model->getMazzo()[static_cast<int>(r)]->getPosseduta()==true?"SI":"NO").contains(s);
    if(a=="Nome")
        return QString::fromStdString(model->getMazzo()[static_cast<int>(r)]->getNome()).contains(s);
    if(a=="Numero")
        return QString::fromStdString(model->getMazzo()[static_cast<int>(r)]->getNumero()).contains(s);
    if(a=="Rarità")
        return QString::fromStdString(model->getMazzo()[static_cast<int>(r)]->getRarita()).contains(s);
    if(a=="Espansione")
        return QString::fromStdString(model->getMazzo()[static_cast<int>(r)]->getEspansione()).contains(s);
    if(a=="Serie")
        return QString::fromStdString(model->getMazzo()[static_cast<int>(r)]->getSerie()).contains(s);
    else
        return false;
}

bool QListModelAdapter::insertRows(int begin, int count, const QModelIndex& parent) {
   beginInsertRows(parent, begin, begin + count - 1);
   model->add(inserisciCarta->getNuovaCarta());
   endInsertRows();
   return true;
}

void QListModelAdapter::loadFromFile(std::string path) {
    model->loadFromFile(path);
}

void QListModelAdapter::fillEditor(const QModelIndex & index) {
    if (index.isValid() && index.row() < rowCount() && index.column()<columnCount()){
        inserisciCarta->show();
        inserisciCarta->fillFromCard(
                    &*(model->getMazzo()[index.row()]),
                QAbstractTableModel::createIndex(index.row(), 0),
                QAbstractTableModel::createIndex(index.row(), columnCount()-1));
        connect(inserisciCarta, SIGNAL(dataChanged(QModelIndex, QModelIndex)), this, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)));
    }
}

void QListModelAdapter::saveToFile(std::string path) const {
    model->saveToFile(path);
}
