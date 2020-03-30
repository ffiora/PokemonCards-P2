#ifndef CARDEDITOR_H
#define CARDEDITOR_H

#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include "MODEL/carta.h"
#include "MODEL/allenatore.h"
#include "MODEL/pokemon.h"
#include "MODEL/energia.h"
#include "GUI/pokemoneditor.h"

class CardEditor: public QWidget{
    Q_OBJECT
private:
    PokemonEditor* pokemonEditor;
    Carta* carta;
    QWidget* pk;
    QVBoxLayout* defaultLayout;
    QLabel * labelPosseduta;
    QComboBox* selectPosseduta;
    QHBoxLayout* posseduta;
    QComboBox* selectSottotipo;
    QLineEdit* nomeCarta;
    QLineEdit* nomeAbilita;
    QComboBox* selectTipoAbilita;
    QHBoxLayout* abilitaPk;
    QHBoxLayout* intestazioneCarta;    
    QTextEdit* testoCarta;
    QLineEdit* serieCarta;
    QLineEdit* espansioneCarta;
    QLineEdit* numeroCarta;
    QComboBox* selectRarita;
    QHBoxLayout* numerazioneCarta;
    QModelIndex begin;
    QModelIndex end;
    QHBoxLayout* view;
    char tipoCarta;
    bool isNew;
    void prepareUI(char);
public:
    CardEditor(QWidget *parent = nullptr);
    ~CardEditor(){}
    void fillFromCard(Carta*,const QModelIndex&, const QModelIndex&);
    void newCard(char);
    Carta* getNuovaCarta();
    void clean();
signals:
    void dataChanged(const QModelIndex&, const QModelIndex&);
    void trySave();
private slots:
    void salva();
};

#endif // CARDEDITOR_H
