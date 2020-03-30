#ifndef POKEMONEDITOR_H
#define POKEMONEDITOR_H

#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <regex>
#include <MODEL/pokemon.h>


class PokemonEditor: public QVBoxLayout{
    Q_OBJECT
private:
    Pokemon* pokemon;
    QLabel* labelPokedex;
    QSpinBox* pokedex;
    QLineEdit* nomeEvolve;
    QHBoxLayout* pokedexevolve;
    QLabel* labelRitirata;
    QSpinBox* costoRitirata;
    QHBoxLayout* ritirata;
    QLabel* labelPv;
    QSpinBox* pvPokemon;
    QHBoxLayout* pv;
    QComboBox* selectTipoPk;
    QComboBox* selectTipoPk2;
    QHBoxLayout* intestazionePk;
    QListWidget* listaMosse;
    QPushButton* rimuoviMossa;
    QPushButton* modificaMossa;
    QPushButton* aggiungiMossa;
    QBoxLayout* modificaListaMossa;
    QLineEdit* nomeMossa;
    QLineEdit* dannoMossa;
    QTextEdit* testoMossa;
    QLabel* labelCostoMossa;
    QHBoxLayout* nomedanno;
    QVBoxLayout* dettagliMossa;
    QHBoxLayout* mossa;
    QListWidget* listaRegole;
    QPushButton* rimuoviRegola;
    QPushButton* modificaRegola;
    QPushButton* aggiungiRegola;
    QVBoxLayout* modificaListaRegola;
    QTextEdit* testoRegola;
    QHBoxLayout* regola;
    QVBoxLayout* Colorless;
    QVBoxLayout* Grass;
    QVBoxLayout* Fire;
    QVBoxLayout* Darkness;
    QVBoxLayout* Water;
    QVBoxLayout* Fairy;
    QVBoxLayout* Fighting;
    QVBoxLayout* Psychic;
    QVBoxLayout* Lighting;
    QVBoxLayout* Metal;
    QVBoxLayout* Dragon;
    QLabel* labelColorless;
    QLabel* labelGrass;
    QLabel* labelFire;
    QLabel* labelDarkness;
    QLabel* labelWater;
    QLabel* labelFairy;
    QLabel* labelFighting;
    QLabel* labelPsychic;
    QLabel* labelLighting;
    QLabel* labelMetal;
    QLabel* labelDragon;
    QSpinBox* costoColorless;
    QSpinBox* costoGrass;
    QSpinBox* costoFire;
    QSpinBox* costoDarkness;
    QSpinBox* costoWater;
    QSpinBox* costoFairy;
    QSpinBox* costoFighting;
    QSpinBox* costoPsychic;
    QSpinBox* costoLighting;
    QSpinBox* costoMetal;
    QLineEdit* debColorless;
    QLineEdit* debGrass;
    QLineEdit* debFire;
    QLineEdit* debDarkness;
    QLineEdit* debWater;
    QLineEdit* debFairy;
    QLineEdit* debFighting;
    QLineEdit* debPsychic;
    QLineEdit* debLighting;
    QLineEdit* debMetal;
    QLineEdit* debDragon;
    QLineEdit* resColorless;
    QLineEdit* resGrass;
    QLineEdit* resFire;
    QLineEdit* resDarkness;
    QLineEdit* resWater;
    QLineEdit* resFairy;
    QLineEdit* resFighting;
    QLineEdit* resPsychic;
    QLineEdit* resLighting;
    QLineEdit* resMetal;
    QLineEdit* resDragon;
    QHBoxLayout* img;
    QLabel* labelVuoto;
    QLabel* labelDeb;
    QLabel* labelRes;
    QVBoxLayout* labels;

    int contaCosto(std::vector<std::string>, std::string) const;
    std::string trovaDebRes(std::vector<Pokemon::DebRes> , std::string) const;
    void riempiMosse(std::vector<Pokemon::Mossa>);
    void riempiRegole(std::vector<std::string>);
    void riempiDebolezze(std::vector<Pokemon::DebRes>);
    void riempiResistenze(std::vector<Pokemon::DebRes>);
    void salvaDebolezze(Pokemon*);
    void salvaResistenze(Pokemon*);
public:
    PokemonEditor();

    void fillFromPokemon(Pokemon*);    
    void salvaPk(Pokemon*);
    void clean();
    std::vector<std::string> riempiCostoMossa(int, std::string);
    void bloccaListe(bool);
private slots:
    void infoMosse();
    void infoRegole();
    void eliminaRegola();
    void salvaMossa();
    void salvaNuovaMossa();
    void eliminaMossa();
    void salvaNuovaRegola();
    void salvaRegola();
};

#endif // POKEMONEDITOR_H
