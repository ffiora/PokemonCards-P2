#include "cardeditor.h"

CardEditor::CardEditor(QWidget *parent )
{
    setWindowTitle("CardEditor");
    setWindowIcon(QIcon(":/IMG/colorless.png"));
    pokemonEditor=new PokemonEditor();
    pk=new QWidget();
    pk->setLayout(pokemonEditor);

    labelPosseduta=new QLabel();
    labelPosseduta->setText("Posseduta");
    selectPosseduta = new QComboBox();
    selectPosseduta->addItem("NO");
    selectPosseduta->addItem("SI");
    posseduta=new QHBoxLayout();
    posseduta->addWidget(labelPosseduta);
    posseduta->addWidget(selectPosseduta);
    //a capo
    selectSottotipo = new QComboBox();//seleziona sottotipo
    nomeCarta= new QLineEdit();//nome
    nomeCarta->setPlaceholderText("Nome");
    intestazioneCarta=new QHBoxLayout();
    intestazioneCarta->addWidget(selectSottotipo);
    intestazioneCarta->addWidget(nomeCarta);
    //a capo
    nomeAbilita= new QLineEdit();//nome abilita
    nomeAbilita->setPlaceholderText("Nome Abilità");
    selectTipoAbilita = new QComboBox();
    selectTipoAbilita->addItem(QString("Nessuna"));
    selectTipoAbilita->addItem(QString("Ability"));
    selectTipoAbilita->addItem(QString("Poké-Power"));
    selectTipoAbilita->addItem(QString("Poké-Body"));
    abilitaPk= new QHBoxLayout();
    abilitaPk->addWidget(nomeAbilita);
    abilitaPk->addWidget(selectTipoAbilita);
    //a capo
    testoCarta = new QTextEdit ();//testo
    testoCarta->setPlaceholderText("Testo");
    //a capo
    serieCarta = new QLineEdit ();//serie
    serieCarta->setPlaceholderText("Serie");
    espansioneCarta = new QLineEdit ();//espansione
    espansioneCarta->setPlaceholderText("Espansione");
    numeroCarta = new QLineEdit ();//numero
    numeroCarta->setPlaceholderText("Numero");
    selectRarita = new QComboBox();//rarità
    selectRarita->addItem(QString("Common"));
    selectRarita->addItem(QString("Uncommon"));
    selectRarita->addItem(QString("Rare"));
    selectRarita->addItem(QString("Rare Holo"));
    selectRarita->addItem(QString("Rare Holo GX"));
    selectRarita->addItem(QString("Rare Holo EX"));
    selectRarita->addItem(QString("Rare Ultra"));
    selectRarita->addItem(QString("Rare Secret"));
    selectRarita->addItem(QString("Promo"));
    selectRarita->addItem(QString("Rare Ace"));
    numerazioneCarta=new QHBoxLayout();
    numerazioneCarta->addWidget(serieCarta);
    numerazioneCarta->addWidget(espansioneCarta);
    numerazioneCarta->addWidget(numeroCarta);
    numerazioneCarta->addWidget(selectRarita);
    QPushButton* salvaButton= new QPushButton("Salva");
    connect(salvaButton, SIGNAL(clicked()), this, SLOT(salva()));

    defaultLayout=new QVBoxLayout;
    defaultLayout->addLayout(posseduta);
    defaultLayout->addLayout(intestazioneCarta);
    defaultLayout->addLayout(abilitaPk);
    defaultLayout->addWidget(testoCarta);
    defaultLayout->addLayout(numerazioneCarta);
    defaultLayout->addWidget(salvaButton);

    view=new QHBoxLayout();
    view->addLayout(defaultLayout);
    view->addWidget(pk);
    this->setLayout(view);
    this->resize(size());
}

void CardEditor::prepareUI(char c)
{
    selectSottotipo->clear();
    switch (c) {
    case 'p':
        selectSottotipo->addItem(QString("Basic"));//pk
        selectSottotipo->addItem(QString("Stage 1"));
        selectSottotipo->addItem(QString("Stage 2"));
        selectSottotipo->addItem(QString("GX"));
        selectSottotipo->addItem(QString("Break"));
        selectSottotipo->addItem(QString("EX"));
        selectSottotipo->addItem(QString("Restored"));
        selectSottotipo->addItem(QString("Level Up"));
        selectSottotipo->addItem(QString("Legend"));
        selectSottotipo->addItem(QString("Mega"));
        break;
    case 'a':
        selectSottotipo->addItem(QString("Pokémon Tool"));//allenatore
        selectSottotipo->addItem(QString("Item"));
        selectSottotipo->addItem(QString("Stadium"));
        selectSottotipo->addItem(QString("Support"));
        selectSottotipo->addItem(QString("Rocket's SM"));
        selectSottotipo->addItem(QString("Tecnical Machine"));
        break;
    case 'e':
        selectSottotipo->addItem(QString("Basic"));
        selectSottotipo->addItem(QString("Special"));//energie
        break;
    }
}

void CardEditor::fillFromCard(Carta* c,const QModelIndex& b, const QModelIndex& e){
    begin=b;
    end=e;
    carta=c;
    clean();
    selectPosseduta->setCurrentText(QString::fromStdString(c->getPosseduta()==true?"SI":"NO"));
    nomeCarta->setText(QString::fromStdString(c->getNome()));
    serieCarta->setText(QString::fromStdString(c->getSerie()));
    espansioneCarta->setText(QString::fromStdString(c->getEspansione()));
    numeroCarta->setText(QString::fromStdString(c->getNumero()));
    selectRarita->setCurrentText(QString::fromStdString(c->getRarita()));

    if(Pokemon* p=dynamic_cast<Pokemon*>(c)){
        prepareUI('p');
        selectSottotipo->setCurrentText(QString::fromStdString(p->getSottotipo()));
        pokemonEditor->fillFromPokemon(p);
        nomeAbilita->setDisabled(false);
        selectTipoAbilita->setDisabled(false);
        if(p->hasAbilita()){
            nomeAbilita->setText(QString::fromStdString(p->getNomeAbilita()));
            selectTipoAbilita->setCurrentText(QString::fromStdString(p->getTipoAbilita()));
            testoCarta->setText(QString::fromStdString(p->getTestoAbilita()));
        }
        pk->show();
    }
    else if(Allenatore* a=dynamic_cast<Allenatore*>(c)){
        nomeAbilita->setDisabled(true);
        selectTipoAbilita->setDisabled(true);
        pk->hide();
        prepareUI('a');
        selectSottotipo->setCurrentText(QString::fromStdString(a->getTipo()));
        testoCarta->setText(QString::fromStdString(a->getTesto()));
    }
    else if(Energia* e=dynamic_cast<Energia*>(c)){
        nomeAbilita->setDisabled(true);
        selectTipoAbilita->setDisabled(true);
        pk->hide();
        prepareUI('e');
        selectSottotipo->setCurrentText((e->getSpeciale())?"Special":"Basic");
        testoCarta->setText(QString::fromStdString(e->getTesto()));
    }
}

void CardEditor::newCard(char t)
{
    tipoCarta=t;
    isNew=true;
    prepareUI(t);
    if (t!='p'){
        nomeAbilita->setDisabled(true);
        selectTipoAbilita->setDisabled(true);
        pk->hide();
    }
    else pk->show();
    pokemonEditor->bloccaListe(true);    
}

Carta *CardEditor::getNuovaCarta()
{
    switch (tipoCarta) {
    case 'a':
          {Allenatore* a=new Allenatore(nomeCarta->text().toStdString(),
                                         espansioneCarta->text().toStdString(),
                                         numeroCarta->text().toStdString(),
                                         selectRarita->currentText().toStdString(),
                                         serieCarta->text().toStdString(),
                                         testoCarta->toPlainText().toStdString(),
                                         selectSottotipo->currentText().toStdString());
              a->setPosseduta(selectPosseduta->currentText().toStdString()=="SI"?true:false);
          return a;}
   case 'e':
        {Energia* e=new Energia(nomeCarta->text().toStdString(),
                                     espansioneCarta->text().toStdString(),
                                     numeroCarta->text().toStdString(),
                                     selectRarita->currentText().toStdString(),
                                     serieCarta->text().toStdString(),
                                     testoCarta->toPlainText().toStdString(),
                                     selectSottotipo->currentText().toStdString()=="Speciale"?true:false);
            e->setPosseduta(selectPosseduta->currentText().toStdString()=="SI"?true:false);
        return e;}
    case 'p':
    {
        Pokemon* p=new Pokemon(nomeCarta->text().toStdString(),
                               espansioneCarta->text().toStdString(),
                               numeroCarta->text().toStdString(),
                               selectRarita->currentText().toStdString(),
                               serieCarta->text().toStdString());
        p->setPosseduta(selectPosseduta->currentText().toStdString()=="SI"?true:false);
        if(selectTipoAbilita->currentText().toStdString()!="Nessuna"){
            p->setAbilita(nomeAbilita->text().toStdString(),testoCarta->toPlainText().toStdString(),selectTipoAbilita->currentText().toStdString());
        }
        pokemonEditor->salvaPk(p);
        return p;
    }
    default:
        QMessageBox box(QMessageBox::Warning, "Errore di inserimento", "Non è stato possibile inserire la carta", QMessageBox::Ok);
        box.exec();
        break;
    }
    return nullptr;
}

void CardEditor::clean()
{
    pokemonEditor->clean();
    selectTipoAbilita->setCurrentText("Nessuna");
    nomeAbilita->clear();
    testoCarta->clear();
    nomeCarta->clear();
    serieCarta->clear();
    espansioneCarta->clear();
    numeroCarta->clear();
    selectRarita->setCurrentText(QString::fromStdString("Common"));

}

void CardEditor::salva()
{
        if(!isNew){
            carta->setPosseduta(selectPosseduta->currentText().toStdString()=="SI"?true:false);
            carta->setNome(nomeCarta->text().toStdString());
            carta->setSerie(serieCarta->text().toStdString());
            carta->setNumero(numeroCarta->text().toStdString());
            carta->setEspansione(espansioneCarta->text().toStdString());
            carta->setRarita(selectRarita->currentText().toStdString());

            if(Pokemon* p=dynamic_cast<Pokemon*>(carta)){
                pokemonEditor->salvaPk(p);
                if(selectTipoAbilita->currentText().toStdString()!="Nessuna"){
                    p->setAbilita(nomeAbilita->text().toStdString(),testoCarta->toPlainText().toStdString(),selectTipoAbilita->currentText().toStdString());
                }else p->togliAbilita();
                p->setSottotipo(selectSottotipo->currentText().toStdString());
            }
            else if(Allenatore* a=dynamic_cast<Allenatore*>(carta)){
                a->setTipo(selectSottotipo->currentText().toStdString());
                a->setTesto(testoCarta->toPlainText().toStdString());
            }
            else if(Energia* e=dynamic_cast<Energia*>(carta)){
                e->setTesto(testoCarta->toPlainText().toStdString());
                e->setSpeciale(selectSottotipo->currentText()=="Special"?true:false);
            }
        }
        else {
            isNew=false;
            pokemonEditor->bloccaListe(false);
            emit trySave();
            this->hide();
        }
        emit dataChanged(begin, end);
}

