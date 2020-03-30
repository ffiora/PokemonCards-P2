#include "pokemoneditor.h"

PokemonEditor::PokemonEditor()
{
    labelPv=new QLabel();// hp
    labelPv->setText("PV");
    pvPokemon = new QSpinBox();
    pvPokemon->setSingleStep(10);
    pvPokemon->setMinimum(10);
    pvPokemon->setMaximum(1000);
    pv=new QHBoxLayout();
    pv->addWidget(labelPv);
    pv->addWidget(pvPokemon);
    selectTipoPk = new QComboBox();//tipo
    selectTipoPk->addItem(QString("Colorless"));
    selectTipoPk->addItem(QString("Grass"));
    selectTipoPk->addItem(QString("Fire"));
    selectTipoPk->addItem(QString("Darkness"));
    selectTipoPk->addItem(QString("Water"));
    selectTipoPk->addItem(QString("Fairy"));
    selectTipoPk->addItem(QString("Fighting"));
    selectTipoPk->addItem(QString("Dragon"));
    selectTipoPk->addItem(QString("Psychic"));
    selectTipoPk->addItem(QString("Lightning"));
    selectTipoPk->addItem(QString("Metal"));
    selectTipoPk2 = new QComboBox();//tipo2
    selectTipoPk2->addItem(QString("-"));
    selectTipoPk2->addItem(QString("Colorless"));
    selectTipoPk2->addItem(QString("Grass"));
    selectTipoPk2->addItem(QString("Fire"));
    selectTipoPk2->addItem(QString("Darkness"));
    selectTipoPk2->addItem(QString("Water"));
    selectTipoPk2->addItem(QString("Fairy"));
    selectTipoPk2->addItem(QString("Fighting"));
    selectTipoPk2->addItem(QString("Dragon"));
    selectTipoPk2->addItem(QString("Psychic"));
    selectTipoPk2->addItem(QString("Lightning"));
    selectTipoPk2->addItem(QString("Metal"));
    intestazionePk= new QHBoxLayout();
    intestazionePk->addLayout(pv);
    intestazionePk->addWidget(selectTipoPk);
    intestazionePk->addWidget(selectTipoPk2);
    //a capo
    labelPokedex=new QLabel();//pokedex
    labelPokedex->setText("Pokedex");
    pokedex = new QSpinBox();
    pokedex->setMinimum(0);
    pokedex->setMaximum(10000);
    nomeEvolve= new QLineEdit();//evolve
    nomeEvolve->setPlaceholderText("Evolve Da");
    pokedexevolve= new QHBoxLayout();
    pokedexevolve->addWidget(labelPokedex);
    pokedexevolve->addWidget(pokedex);
    pokedexevolve->addWidget(nomeEvolve);
    //a capo
    labelRitirata=new QLabel();// costo Ritirata
    labelRitirata->setText("Costo Ritirata");
    costoRitirata = new QSpinBox();
    costoRitirata->setMinimum(0);
    costoRitirata->setMaximum(4);
    ritirata=new QHBoxLayout();
    ritirata->addWidget(labelRitirata);
    ritirata->addWidget(costoRitirata);
    //a capo
    listaMosse= new QListWidget();//lista mosse
    connect(listaMosse,SIGNAL(itemSelectionChanged()),this,SLOT(infoMosse()));
    rimuoviMossa= new QPushButton("Rimuovi");
    connect(rimuoviMossa,SIGNAL(clicked()),this,SLOT(eliminaMossa()));
    modificaMossa= new QPushButton("Modifica");
    connect(modificaMossa,SIGNAL(clicked()),this,SLOT(salvaMossa()));
    aggiungiMossa= new QPushButton("Aggiungi");
    connect(aggiungiMossa,SIGNAL(clicked()),this,SLOT(salvaNuovaMossa()));
    modificaListaMossa=new QVBoxLayout();
    modificaListaMossa->addWidget(listaMosse);
    modificaListaMossa->addWidget(rimuoviMossa);
    modificaListaMossa->addWidget(modificaMossa);
    modificaListaMossa->addWidget(aggiungiMossa);
    nomeMossa=new QLineEdit();
    nomeMossa->setPlaceholderText("Nome Mossa");
    dannoMossa=new QLineEdit();
    dannoMossa->setPlaceholderText("Danno");
    nomedanno= new QHBoxLayout();
    nomedanno->addWidget(nomeMossa);
    nomedanno->addWidget(dannoMossa);
    testoMossa=new QTextEdit();
    testoMossa->setPlaceholderText("Testo Mossa");
    dettagliMossa=new QVBoxLayout();
    dettagliMossa->addLayout(nomedanno);
    dettagliMossa->addWidget(testoMossa);
    mossa=new QHBoxLayout();
    mossa->addLayout(modificaListaMossa);
    mossa->addLayout(dettagliMossa);
    //a capo
    labelVuoto= new QLabel();
    labelVuoto->setText("lol");
    labelCostoMossa=new QLabel();
    labelCostoMossa->setText("Costo Mossa Selezionata");
    labelDeb=new QLabel();
    labelDeb->setText("Debolezze");
    labelRes=new QLabel();
    labelRes->setText("Resistenze");
    labels=new QVBoxLayout();
    Colorless= new QVBoxLayout();//colori
    Grass= new QVBoxLayout();
    Fire= new QVBoxLayout();
    Darkness= new QVBoxLayout();
    Water= new QVBoxLayout();
    Fairy= new QVBoxLayout();
    Fighting= new QVBoxLayout();
    Psychic= new QVBoxLayout();
    Lighting= new QVBoxLayout();
    Metal= new QVBoxLayout();
    Dragon= new QVBoxLayout();
    labelColorless= new QLabel();
    labelGrass= new QLabel();
    labelFire= new QLabel();
    labelDarkness= new QLabel();
    labelWater= new QLabel();
    labelFairy= new QLabel();
    labelFighting= new QLabel();
    labelPsychic= new QLabel();
    labelLighting= new QLabel();
    labelMetal= new QLabel();
    labelDragon=new QLabel();
    labelColorless->setPixmap(QPixmap(":/IMG/colorless.png"));
    labelGrass->setPixmap(QPixmap(":/IMG/grass.png"));
    labelFire->setPixmap(QPixmap(":/IMG/fire.png"));
    labelDarkness->setPixmap(QPixmap(":/IMG/darkness.png"));
    labelWater->setPixmap(QPixmap(":/IMG/water.png"));
    labelFairy->setPixmap(QPixmap(":/IMG/fairy.png"));
    labelFighting->setPixmap(QPixmap(":/IMG/fighting.png"));
    labelPsychic->setPixmap(QPixmap(":/IMG/psychic.png"));
    labelLighting->setPixmap(QPixmap(":/IMG/lighting.png"));
    labelMetal->setPixmap(QPixmap(":/IMG/metal.png"));
    labelDragon->setPixmap(QPixmap(":/IMG/dragon.png"));
    costoColorless=new QSpinBox();//costo mosse
    costoGrass=new QSpinBox();
    costoFire=new QSpinBox();
    costoDarkness=new QSpinBox();
    costoWater=new QSpinBox();
    costoFairy=new QSpinBox();
    costoFighting=new QSpinBox();
    costoPsychic=new QSpinBox();
    costoLighting=new QSpinBox();
    costoMetal=new QSpinBox();
    debColorless=new QLineEdit();//debolezze
    debGrass=new QLineEdit();
    debFire=new QLineEdit();
    debDarkness=new QLineEdit();
    debWater=new QLineEdit();
    debFairy=new QLineEdit();
    debFighting=new QLineEdit();
    debPsychic=new QLineEdit();
    debLighting=new QLineEdit();
    debMetal=new QLineEdit();
    debDragon=new QLineEdit();
    resColorless=new QLineEdit();//resistenze
    resGrass=new QLineEdit();
    resFire=new QLineEdit();
    resDarkness=new QLineEdit();
    resWater=new QLineEdit();
    resFairy=new QLineEdit();
    resFighting=new QLineEdit();
    resPsychic=new QLineEdit();
    resLighting=new QLineEdit();
    resMetal=new QLineEdit();
    resDragon=new QLineEdit();
    labels->addWidget(labelCostoMossa);//unisco
    labels->addWidget(labelVuoto);
    labels->addWidget(labelDeb);
    labels->addWidget(labelRes);
    Colorless->addWidget(costoColorless);
    Colorless->addWidget(labelColorless);
    Colorless->addWidget(debColorless);
    Colorless->addWidget(resColorless);
    Grass->addWidget(costoGrass);
    Grass->addWidget(labelGrass);
    Grass->addWidget(debGrass);
    Grass->addWidget(resGrass);
    Fire->addWidget(costoFire);
    Fire->addWidget(labelFire);
    Fire->addWidget(debFire);
    Fire->addWidget(resFire);
    Darkness->addWidget(costoDarkness);
    Darkness->addWidget(labelDarkness);
    Darkness->addWidget(debDarkness);
    Darkness->addWidget(resDarkness);
    Water->addWidget(costoWater);
    Water->addWidget(labelWater);
    Water->addWidget(debWater);
    Water->addWidget(resWater);
    Fairy->addWidget(costoFairy);
    Fairy->addWidget(labelFairy);
    Fairy->addWidget(debFairy);
    Fairy->addWidget(resFairy);
    Fighting->addWidget(costoFighting);
    Fighting->addWidget(labelFighting);
    Fighting->addWidget(debFighting);
    Fighting->addWidget(resFighting);
    Psychic->addWidget(costoPsychic);
    Psychic->addWidget(labelPsychic);
    Psychic->addWidget(debPsychic);
    Psychic->addWidget(resPsychic);
    Lighting->addWidget(costoLighting);
    Lighting->addWidget(labelLighting);
    Lighting->addWidget(debLighting);
    Lighting->addWidget(resLighting);
    Metal->addWidget(costoMetal);
    Metal->addWidget(labelMetal);
    Metal->addWidget(debMetal);
    Metal->addWidget(resMetal);
    Dragon->addWidget(labelVuoto);
    Dragon->addWidget(labelDragon);
    Dragon->addWidget(debDragon);
    Dragon->addWidget(resDragon);
    img=new QHBoxLayout();
    img->addLayout(labels);
    img->addLayout(Colorless);
    img->addLayout(Grass);
    img->addLayout(Fire);
    img->addLayout(Darkness);
    img->addLayout(Water);
    img->addLayout(Fairy);
    img->addLayout(Fighting);
    img->addLayout(Psychic);
    img->addLayout(Lighting);
    img->addLayout(Metal);
    img->addLayout(Dragon);
    //a capo
    listaRegole= new QListWidget();//lista regole
    connect(listaRegole,SIGNAL(itemSelectionChanged()),this,SLOT(infoRegole()));
    rimuoviRegola= new QPushButton("Rimuovi");
    connect(rimuoviRegola,SIGNAL(clicked()),this,SLOT(eliminaRegola()));
    modificaRegola= new QPushButton("Modifica");
    connect(modificaRegola,SIGNAL(clicked()),this,SLOT(salvaRegola()));
    aggiungiRegola= new QPushButton("Aggiungi");
    connect(aggiungiRegola,SIGNAL(clicked()),this,SLOT(salvaNuovaRegola()));
    modificaListaRegola=new QVBoxLayout();
    modificaListaRegola->addWidget(listaRegole);
    modificaListaRegola->addWidget(rimuoviRegola);
    modificaListaRegola->addWidget(modificaRegola);
    modificaListaRegola->addWidget(aggiungiRegola);
    testoRegola=new QTextEdit();
    testoRegola->setPlaceholderText("Testo Regola");
    regola=new QHBoxLayout();
    regola->addLayout(modificaListaRegola);
    regola->addWidget(testoRegola);

    this->addLayout(intestazionePk);
    this->addLayout(pokedexevolve);
    this->addLayout(ritirata);
    this->addLayout(mossa);
    this->addLayout(img);
    this->addLayout(regola);
}
void PokemonEditor::riempiMosse(std::vector<Pokemon::Mossa> mosse){
    QListWidgetItem *riga;
    for(auto it: mosse){
        riga= new QListWidgetItem;
        riga->setText(QString::fromStdString(it.getNome()));
        listaMosse->addItem(riga);
    }
}
int PokemonEditor::contaCosto(std::vector<std::string> mosse, std::string s) const
{
    int n=0;
    for(auto it: mosse){
        if (it==s) n++;
    }
    return n;
}
void PokemonEditor::infoMosse(){
    Pokemon::Mossa mossa= pokemon->cercaMossa((listaMosse->currentItem()->text()).toStdString());
    nomeMossa->setText(QString::fromStdString(mossa.getNome()));
    dannoMossa->setText(QString::fromStdString(mossa.getDanno()));
    testoMossa->setText(QString::fromStdString(mossa.getTesto()));
    costoColorless->setValue(contaCosto(mossa.getCosto(),"Colorless"));
    costoGrass->setValue(contaCosto(mossa.getCosto(),"Grass"));
    costoFire->setValue(contaCosto(mossa.getCosto(),"Fire"));
    costoDarkness->setValue(contaCosto(mossa.getCosto(),"Darkness"));
    costoWater->setValue(contaCosto(mossa.getCosto(),"Water"));
    costoFairy->setValue(contaCosto(mossa.getCosto(),"Fairy"));
    costoFighting->setValue(contaCosto(mossa.getCosto(),"Fighting"));
    costoPsychic->setValue(contaCosto(mossa.getCosto(),"Psychic"));
    costoLighting->setValue(contaCosto(mossa.getCosto(),"Lighting"));
    costoMetal->setValue(contaCosto(mossa.getCosto(),"Metal"));
}
std::string PokemonEditor::trovaDebRes(std::vector<Pokemon::DebRes> dr, std::string s) const
{
    for(auto it: dr){
        if(it.getTipo()==s) return it.getValore();
    }
    return "";
}
void PokemonEditor::riempiDebolezze(std::vector<Pokemon::DebRes> deb){
    debColorless->setText(QString::fromStdString(trovaDebRes(deb,"Colorless")));
    debGrass->setText(QString::fromStdString(trovaDebRes(deb,"Grass")));
    debFire->setText(QString::fromStdString(trovaDebRes(deb,"Fire")));
    debDarkness->setText(QString::fromStdString(trovaDebRes(deb,"Darkness")));
    debWater->setText(QString::fromStdString(trovaDebRes(deb,"Water")));
    debFairy->setText(QString::fromStdString(trovaDebRes(deb,"Fairy")));
    debFighting->setText(QString::fromStdString(trovaDebRes(deb,"Fighting")));
    debPsychic->setText(QString::fromStdString(trovaDebRes(deb,"Psychic")));
    debLighting->setText(QString::fromStdString(trovaDebRes(deb,"Lighting")));
    debMetal->setText(QString::fromStdString(trovaDebRes(deb,"Metal")));
    debDragon->setText(QString::fromStdString(trovaDebRes(deb,"Dragon")));
}

void PokemonEditor::riempiResistenze(std::vector<Pokemon::DebRes> res){
    resColorless->setText(QString::fromStdString(trovaDebRes(res,"Colorless")));
    resGrass->setText(QString::fromStdString(trovaDebRes(res,"Grass")));
    resFire->setText(QString::fromStdString(trovaDebRes(res,"Fire")));
    resDarkness->setText(QString::fromStdString(trovaDebRes(res,"Darkness")));
    resWater->setText(QString::fromStdString(trovaDebRes(res,"Water")));
    resFairy->setText(QString::fromStdString(trovaDebRes(res,"Fairy")));
    resFighting->setText(QString::fromStdString(trovaDebRes(res,"Fighting")));
    resPsychic->setText(QString::fromStdString(trovaDebRes(res,"Psychic")));
    resLighting->setText(QString::fromStdString(trovaDebRes(res,"Lighting")));
    resMetal->setText(QString::fromStdString(trovaDebRes(res,"Metal")));
    resDragon->setText(QString::fromStdString(trovaDebRes(res,"Dragon")));
}

void PokemonEditor::riempiRegole(std::vector<std::string> regole){
    QListWidgetItem *riga;
    for(auto it: regole){
        riga= new QListWidgetItem;
        riga->setText(QString::fromStdString(it));
        listaRegole->addItem(riga);
    }
}
void PokemonEditor::infoRegole(){
    std::string regola= pokemon->cercaRegola((listaRegole->currentItem()->text()).toStdString());
    testoRegola->setText(QString::fromStdString(regola));
}

void PokemonEditor::eliminaMossa()
{
    if(listaMosse->currentIndex().isValid()){
        std::string s=(listaMosse->currentItem()->text()).toStdString();
        listaMosse->clear();
        nomeMossa->clear();
        dannoMossa->clear();
        testoMossa->clear();
        costoColorless->clear();
        costoGrass->clear();
        costoFire->clear();
        costoDarkness->clear();
        costoWater->clear();
        costoFairy->clear();
        costoFighting->clear();
        costoPsychic->clear();
        costoLighting->clear();
        costoMetal->clear();
        pokemon->eliminaMossa(s);
        riempiMosse(pokemon->getMosse());
    }
}

void PokemonEditor::salvaNuovaRegola()
{
    std::string nuova=testoRegola->toPlainText().toStdString();
    bool sipuo=true;
    if (std::regex_match (nuova, std::regex("[^\\s].*") )) {
        for(auto it:pokemon->getRegole()) {
            if(it==nuova) sipuo=false;
        }
        if(sipuo){
            pokemon->addRegola(nuova);
            testoRegola->clear();
            listaRegole->clear();
            riempiRegole(pokemon->getRegole());
        }else {
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non possono esserci più regole con lo stesso testo", QMessageBox::Ok);
            box.exec();
        }
    }else {
        QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Inserire il testo della regola", QMessageBox::Ok);
        box.exec();
    }
}

void PokemonEditor::salvaRegola()
{
    if(listaRegole->currentIndex().isValid()){
        std::string nuova=testoRegola->toPlainText().toStdString();
        if (std::regex_match (nuova, std::regex("[^\\s].*") )) {
            bool sipuo=true;
            std::string vecchia=(listaRegole->currentItem()->text()).toStdString();
            for(auto it:pokemon->getRegole()) {
                if(it==nuova) sipuo=false;
            }
            if(sipuo){
                listaRegole->clear();
                pokemon->modificaRegola(nuova,vecchia);
                testoRegola->clear();
                riempiRegole(pokemon->getRegole());
            }else {
                QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non possono esserci più regole con lo stesso testo", QMessageBox::Ok);
                box.exec();
        }
        }else            {
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Inserire il testo della regola", QMessageBox::Ok);
            box.exec();
        }
    }
}


void PokemonEditor::eliminaRegola()
{
    if(listaRegole->currentIndex().isValid()){
        std::string s=(listaRegole->currentItem()->text()).toStdString();
        listaRegole->clear();
        testoRegola->clear();
        pokemon->eliminaRegola(s);
        riempiRegole(pokemon->getRegole());
    }
}
std::vector<std::string> PokemonEditor::riempiCostoMossa(int n, std::string s)
{
    std::vector<std::string> costo;
    for(int i=0;i<n;i++){
        costo.push_back(s);
    }
    return costo;
}

void PokemonEditor::bloccaListe(bool b)
{
    modificaMossa->setDisabled(b);
    modificaRegola->setDisabled(b);
    aggiungiMossa->setDisabled(b);
    aggiungiRegola->setDisabled(b);
    rimuoviMossa->setDisabled(b);
    rimuoviRegola->setDisabled(b);
}
void PokemonEditor::salvaMossa()
{
    if(listaMosse->currentIndex().isValid()){
        std::string nome=nomeMossa->text().toStdString();
        if (std::regex_match (nome, std::regex("[^\\s].*") )) {
            bool sipuo=true;
            int count=0;
            for(auto it:pokemon->getMosse()) {
                if(it.getNome()==nome) count++;
            }
            if (count>=1 && nome!=listaMosse->currentItem()->text().toStdString()) sipuo=false;
            if(sipuo){
            std::vector<std::string> costo;
            if(costoColorless->value()){
                for(int i=0;i<costoColorless->value();i++){
                    costo.push_back("Colorless");
                }
            }if(costoGrass->value()){
                for(int i=0;i<costoGrass->value();i++){
                    costo.push_back("Grass");
                }
            }if (costoFire->value()) {
                for(int i=0;i<costoFire->value();i++){
                    costo.push_back("Fire");
                }
            }if (costoDarkness->value()) {
                for(int i=0;i<costoDarkness->value();i++){
                    costo.push_back("Darkness");
                }
            }if (costoWater->value()) {
                for(int i=0;i<costoWater->value();i++){
                    costo.push_back("Water");
                }
            }if (costoFairy->value()) {
                for(int i=0;i<costoFairy->value();i++){
                    costo.push_back("Fairy");
                }
            }if (costoFighting->value()) {
                for(int i=0;i<costoFighting->value();i++){
                    costo.push_back("Fighting");
                }
            }if (costoPsychic->value()) {
                for(int i=0;i<costoPsychic->value();i++){
                    costo.push_back("Psychic");
                }
            }if (costoLighting->value()) {
                for(int i=0;i<costoLighting->value();i++){
                    costo.push_back("Lighting");
                }
            }if (costoMetal->value()) {
                for(int i=0;i<costoMetal->value();i++){
                    costo.push_back("Metal");
                }
           }
            std::string vecchia =(listaMosse->currentItem()->text()).toStdString();
            std::string danno=dannoMossa->text().toStdString();
            std::string testo=testoMossa->toPlainText().toStdString();
            listaMosse->clear();
            pokemon->modificaMossa(nome,danno,testo,costo,vecchia);
            nomeMossa->clear();
            dannoMossa->clear();
            testoMossa->clear();
            costoColorless->clear();
            costoGrass->clear();
            costoFire->clear();
            costoDarkness->clear();
            costoWater->clear();
            costoFairy->clear();
            costoFighting->clear();
            costoPsychic->clear();
            costoLighting->clear();
            costoMetal->clear();
            riempiMosse(pokemon->getMosse());
            }else {
                QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non possono esserci più mosse con lo stesso nome", QMessageBox::Ok);
                box.exec();
            }
        } else{
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Inserire il nome della mossa", QMessageBox::Ok);
            box.exec();
        }
    }
}

void PokemonEditor::salvaNuovaMossa()
{
    std::string nome=nomeMossa->text().toStdString();
    if (std::regex_match (nome, std::regex("[^\\s].*") )) {
        bool sipuo=true;
        for(auto it:pokemon->getMosse()) {
            if(it.getNome()==nome) sipuo=false;
        }
        if(sipuo){
        std::vector<std::string> costo;
        if(costoColorless->value()){
            for(int i=0;i<costoColorless->value();i++){
                costo.push_back("Colorless");
            }
        }if (costoFire->value()) {
            for(int i=0;i<costoFire->value();i++){
                costo.push_back("Fire");
            }
        }if (costoDarkness->value()) {
            for(int i=0;i<costoDarkness->value();i++){
                costo.push_back("Darkness");
            }
        }if (costoWater->value()) {
            for(int i=0;i<costoWater->value();i++){
                costo.push_back("Water");
            }
        }if (costoFairy->value()) {
            for(int i=0;i<costoFairy->value();i++){
                costo.push_back("Fairy");
            }
        }if (costoFighting->value()) {
            for(int i=0;i<costoFighting->value();i++){
                costo.push_back("Fighting");
            }
        }if (costoPsychic->value()) {
            for(int i=0;i<costoPsychic->value();i++){
                costo.push_back("Psychic");
            }
        }if (costoLighting->value()) {
            for(int i=0;i<costoLighting->value();i++){
                costo.push_back("Lighting");
            }
        }if (costoMetal->value()) {
            for(int i=0;i<costoMetal->value();i++){
                costo.push_back("Metal");
            }
       }
            std::string danno=dannoMossa->text().toStdString();
            std::string testo=testoMossa->toPlainText().toStdString();
            pokemon->addMossa(nome,danno,testo,costo);
            nomeMossa->clear();
            dannoMossa->clear();
            testoMossa->clear();
            costoColorless->clear();
            costoGrass->clear();
            costoFire->clear();
            costoDarkness->clear();
            costoWater->clear();
            costoFairy->clear();
            costoFighting->clear();
            costoPsychic->clear();
            costoLighting->clear();
            costoMetal->clear();
            listaMosse->clear();
            riempiMosse(pokemon->getMosse());
        }else {
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non possono esserci più mosse con lo stesso nome", QMessageBox::Ok);
            box.exec();
        }
    }else{
        QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Inserire il nome della mossa", QMessageBox::Ok);
        box.exec();
    }
}
void PokemonEditor::fillFromPokemon(Pokemon* p){
    pokemon=p;
    pvPokemon->setValue(static_cast<int>(p->getPv()));
    pokedex->setValue(static_cast<int>(p->getNumeroPokedex()));
    nomeEvolve->setText(QString::fromStdString(p->getEvolveDa()));
    costoRitirata->setValue(static_cast<int>(p->getCostoRitirata()));
    switch (p->getTipi().size()) {
    case 2:
        selectTipoPk2->setCurrentText(QString::fromStdString(p->getTipi()[1]));
    [[clang::fallthrough]]; case 1:
        selectTipoPk->setCurrentText(QString::fromStdString(p->getTipi()[0]));
        break;
    default:
        break;
    }
    riempiMosse(p->getMosse());
    riempiRegole(p->getRegole());
    riempiDebolezze(p->getDebolezze());
    riempiResistenze(p->getResistenze());
}

void PokemonEditor::salvaDebolezze(Pokemon* pv)
{
    Pokemon* p=new Pokemon;
    if (std::regex_match (debColorless->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Colorless",debColorless->text().toStdString());
    if (std::regex_match (debGrass->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Grass",debGrass->text().toStdString());
    if (std::regex_match (debFire->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Fire",debFire->text().toStdString());
    if (std::regex_match (debDarkness->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Darkness",debDarkness->text().toStdString());
    if (std::regex_match (debWater->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Water",debWater->text().toStdString());
    if (std::regex_match (debFairy->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Fairy",debFairy->text().toStdString());
    if (std::regex_match (debFighting->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Fighting",debFighting->text().toStdString());
    if (std::regex_match (debPsychic->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Psychic",debPsychic->text().toStdString());
    if (std::regex_match (debLighting->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Lightning",debLighting->text().toStdString());
    if (std::regex_match (debMetal->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Metal",debMetal->text().toStdString());
    if (std::regex_match (debDragon->text().toStdString(), std::regex("[^\\s].*") )) p->addDeb("Dragon",debDragon->text().toStdString());
    pv->setDebolezze(p->getDebolezze());
}
void PokemonEditor::salvaResistenze(Pokemon* pv)
{
    Pokemon* p=new Pokemon;
    if (std::regex_match (resColorless->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Colorless",resColorless->text().toStdString());
    if (std::regex_match (resGrass->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Grass",resGrass->text().toStdString());
    if (std::regex_match (resFire->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Fire",resFire->text().toStdString());
    if (std::regex_match (resDarkness->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Darkness",resDarkness->text().toStdString());
    if (std::regex_match (resWater->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Water",resWater->text().toStdString());
    if (std::regex_match (resFairy->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Fairy",resFairy->text().toStdString());
    if (std::regex_match (resFighting->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Fighting",resFighting->text().toStdString());
    if (std::regex_match (resPsychic->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Psychic",resPsychic->text().toStdString());
    if (std::regex_match (resLighting->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Lightning",resLighting->text().toStdString());
    if (std::regex_match (resMetal->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Metal",resMetal->text().toStdString());
    if (std::regex_match (resDragon->text().toStdString(), std::regex("[^\\s].*") )) p->addRes("Dragon",resDragon->text().toStdString());
    pv->setResistenze(p->getResistenze());
}
void PokemonEditor::salvaPk(Pokemon * p){
    pokemon=p;
    p->setPv(static_cast<unsigned int>(pvPokemon->value()));
    p->setNumeroPokedex(static_cast<unsigned int>(pokedex->value()));
    p->setEvolveDa(nomeEvolve->text().toStdString());
    p->setCostoRitirata(static_cast<unsigned int>(costoRitirata->value()));
    switch (p->getTipi().size()) {
    case 2:
        p->setTipiConPos(selectTipoPk2->currentText().toStdString(),1);
    [[clang::fallthrough]]; case 1:
        p->setTipiConPos(selectTipoPk->currentText().toStdString(),0);
        break;
    default:
        break;
    }
    salvaDebolezze(p);
    salvaResistenze(p);
}
void PokemonEditor::clean(){
    pvPokemon->clear();
    selectTipoPk->setCurrentText("Colorless");
    selectTipoPk2->setCurrentText("-");
    pokedex->clear();
    nomeEvolve->clear();
    costoRitirata->clear();

    listaMosse->clear();
    nomeMossa->clear();
    dannoMossa->clear();
    testoMossa->clear();
    costoColorless->clear();
    costoGrass->clear();
    costoFire->clear();
    costoDarkness->clear();
    costoWater->clear();
    costoFairy->clear();
    costoFighting->clear();
    costoPsychic->clear();
    costoLighting->clear();
    costoMetal->clear();

    debColorless->clear();//debolezze
    debGrass->clear();
    debFire->clear();
    debDarkness->clear();
    debWater->clear();
    debFairy->clear();
    debFighting->clear();
    debPsychic->clear();
    debLighting->clear();
    debMetal->clear();
    debDragon->clear();

    resColorless->clear();//resistenze
    resGrass->clear();
    resFire->clear();
    resDarkness->clear();
    resWater->clear();
    resFairy->clear();
    resFighting->clear();
    resPsychic->clear();
    resLighting->clear();
    resMetal->clear();
    resDragon->clear();

    listaRegole->clear();
    testoRegola->clear();

}
