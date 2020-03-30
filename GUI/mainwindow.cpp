#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent )
{
    setWindowTitle("PokemonCards");
    setWindowIcon(QIcon(":/IMG/colorless.png"));
    QWidget *w_principale = new QWidget();
    QComboBox* searchAttribute = new QComboBox();
    inserisciCarta=new CardEditor();
    proxymodel = new QFilterProxyModel(this,searchAttribute);
    madapter = new QListModelAdapter(this,inserisciCarta);
    loadData();
    proxymodel->setSourceModel(madapter);
    view=new TableView();
    view->setModel(proxymodel);

    //SEARCH
    searchbar= new QLineEdit();
    searchbar->setPlaceholderText("Ricerca");
    searchAttribute->addItem(QString("Nome"));
    searchAttribute->addItem(QString("Numero"));
    searchAttribute->addItem(QString("Rarità"));
    searchAttribute->addItem(QString("Espansione"));
    searchAttribute->addItem(QString("Serie"));
    searchAttribute->addItem(QString("Posseduta"));
    connect(searchbar, SIGNAL(textChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(searchAttribute, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));

    QHBoxLayout* searchLayout= new QHBoxLayout();
    searchLayout->addWidget(searchAttribute);
    searchLayout->addWidget(searchbar);
    textFilterChanged();

    //DELETE
    QPushButton* deleteButton = new QPushButton("Elimina");
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(rimuovi()));
    QPushButton* deleteResButton = new QPushButton("Elimina risultati");
    connect(deleteResButton, SIGNAL(clicked()), this, SLOT(rimuoviRisultati()));

    //MODIFICA
    QPushButton* modificaButton = new QPushButton("Modifica");
    connect(modificaButton, SIGNAL(clicked()), this, SLOT(fillEditor()));

    QHBoxLayout* edit=new QHBoxLayout();
    edit->addWidget(deleteButton);
    edit->addWidget(deleteResButton);
    edit->addWidget(modificaButton);

    //INSERISCI
    selectTipo=new QComboBox();
    selectTipo->addItem("Pokemon");
    selectTipo->addItem("Allenatore");
    selectTipo->addItem("Energia");
    QPushButton* inserisciButton = new QPushButton("Inserisci");
    connect(inserisciButton, SIGNAL(clicked()), this, SLOT(newEditor()));

    QHBoxLayout* insert=new QHBoxLayout();
    insert->addWidget(selectTipo);
    insert->addWidget(inserisciButton);
    connect(inserisciCarta, SIGNAL(trySave()), this, SLOT(aggiungiCarta()));

    //SALVA
    QPushButton* salvaButton = new QPushButton("Salva");
    connect(salvaButton, SIGNAL(clicked()), this, SLOT(saveData()));


    QVBoxLayout* tableLayout = new QVBoxLayout();
    view->setMaximumWidth(800);
    tableLayout->addWidget(view, 0, Qt::AlignCenter);
    tableLayout->addLayout(searchLayout);
    tableLayout->addLayout(edit);
    tableLayout->addLayout(insert);
    tableLayout->addWidget(salvaButton);


    //MAIN
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addLayout(tableLayout);
    w_principale->setLayout(mainLayout);
    this->setCentralWidget(w_principale);
}

void MainWindow::textFilterChanged() const {
    QRegExp regex(searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxymodel->setFilterRegExp(regex);
}

void MainWindow::rimuovi()const {
    const QModelIndexList selection = view->selectionModel()->selectedIndexes();
    if(selection.size() > 0)
        proxymodel->removeRows(selection.at(0).row(), 1);
}

void MainWindow::rimuoviRisultati() const
{
    proxymodel->removeResults();
}

void MainWindow::loadData() {
    fileName = QFileDialog::getOpenFileName(this,tr("Load from file"), "",tr("JSON (*.json);;All Files (*)"));
    if(!fileName.isEmpty()){
        madapter->loadFromFile(fileName.toStdString());
    }
}
void MainWindow::fillEditor() const{
    const QModelIndexList selection = view->selectionModel()->selectedIndexes();
    if(selection.size() > 0)
        proxymodel->fillEditor(selection.at(0));
}

void MainWindow::newEditor() const
{
    inserisciCarta->clean();
    char c;
    if(selectTipo->currentText().toStdString()=="Pokemon") c='p';
    if(selectTipo->currentText().toStdString()=="Allenatore") c='a';
    if(selectTipo->currentText().toStdString()=="Energia") c='e';
    inserisciCarta->show();
    inserisciCarta->newCard(c);
}

void MainWindow::aggiungiCarta() const{
    proxymodel->insertRows(proxymodel->rowCount(), 1);
    view->clearSelection();
    view->selectionModel()->clearCurrentIndex();
    view->selectionModel()->select(proxymodel->index(madapter->rowCount() - 1, 0), QItemSelectionModel::Select);
}

void MainWindow::saveData() {
    fileName = QFileDialog::getSaveFileName(this,tr("Save to file"), "",tr("JSON (*.json);;All Files (*)"));
    if(!fileName.isEmpty()){
        madapter->saveToFile(fileName.toStdString());
    }
}
