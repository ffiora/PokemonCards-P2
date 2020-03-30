#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<string>
#include <QLayout>
#include <QComboBox>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMainWindow>
#include "MODEL/qfilterproxymodel.h"
#include "MODEL/qlistmodeladapter.h"
#include "MODEL/model.h"
#include "GUI/tableview.h"
#include "cardeditor.h"


class MainWindow : public QMainWindow{
Q_OBJECT
private:
    TableView* view;
    QFilterProxyModel *proxymodel;
    QListModelAdapter* madapter;
    QLineEdit* searchbar;
    CardEditor* inserisciCarta;
    QComboBox* selectTipo;
    QString fileName;
    void loadData();
public:
    MainWindow( QWidget *parent = nullptr);
    ~MainWindow(){}
private slots:
    void rimuovi()const;
    void rimuoviRisultati()const;
    void textFilterChanged() const;
    void fillEditor() const;
    void newEditor()const;
    void aggiungiCarta() const;
    void saveData() ;
};

#endif // MAINWINDOW_H
