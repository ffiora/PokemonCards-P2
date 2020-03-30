#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <vector>
#include "carta.h"

class Pokemon: public Carta{
public:
    class Mossa;
    class DebRes;
private:
    unsigned int numeroPokedex;
    unsigned int pv;    
    unsigned int costoRitirata;
    std::string sottotipo;
    std::string evolveDa;
    std::string nomeAbilita;
    std::string testoAbilita;
    std::string tipoAbilita;

    std::vector<std::string> tipi;
    std::vector<std::string> regole;

    std::vector<Mossa> mosse;

    std::vector<DebRes> debolezze;
    std::vector<DebRes> resistenze;

public:
    Pokemon(std::string = "", std::string = "",std::string = "", std::string ="", std::string="",
            unsigned int =0, std::string ="",unsigned int =0);

    class DebRes{
        friend class Pokemon;
    private:
        std::string tipo;
        std::string valore;
        DebRes(std::string ="",std::string ="");
    public:
        std::string getTipo() const;
        std::string getValore() const;
    };

    class Mossa{
        friend class Pokemon;
    private:
        std::string nome;
        std::string danno;
        std::string testo;
        std::vector<std::string> costo;
        Mossa(std::vector<std::string>,std::string = "",std::string ="",std::string = "");
        void setCosto(const std::vector<std::string> &value);
    public:
        std::string getNome() const;
        std::string getDanno() const;
        std::string getTesto() const;
        std::vector<std::string> getCosto() const;
    };
    //get
    unsigned int getPv() const;
    unsigned int getNumeroPokedex() const;
    unsigned int getCostoRitirata() const;
    std::string getEvolveDa() const;
    std::string getSottotipo() const;
    std::vector<Mossa> getMosse() const;
    std::vector<std::string> getRegole() const;
    std::vector<DebRes> getDebolezze() const;
    std::vector<DebRes> getResistenze() const;
    std::vector<std::string> getTipi() const;
    std::string getNomeAbilita() const;
    std::string getTestoAbilita() const;
    std::string getTipoAbilita() const;
    //set
    void setCostoRitirata(unsigned int value);
    void setEvolveDa(const std::string &value);
    void setTipiConPos(const std::string &value,unsigned int);
    void setRegole(const std::vector<std::string> &value);
    void setNumeroPokedex(unsigned int value);
    void setSottotipo(const std::string &value);
    void setPv(unsigned int value);
    void setNomeAbilita(const std::string &value);
    void setTestoAbilita(const std::string &value);
    void setTipoAbilita(const std::string &value);
    void setDebolezze(const std::vector<DebRes> &value);
    void setResistenze(const std::vector<DebRes> &value);
    void setTipi(const std::vector<std::string> &value);
    void setAbilita(std::string,std::string,std::string);
    //add
    void addRegola(std::string);
    void addMossa(std::string,std::string,std::string,std::vector<std::string>);
    void addDeb(std::string,std::string);
    void addRes(std::string,std::string);
    //modifica
    void modificaMossa(std::string,std::string,std::string,std::vector<std::string>,std::string);
    void modificaRegola(std::string,std::string);
    //cerca
    Mossa cercaMossa(std::string) const;
    std::string cercaRegola(std::string) const;
    //elimina
    void eliminaMossa(std::string);
    void eliminaRegola(std::string);
    //
    virtual Pokemon* clone() const;
    void togliAbilita();
    bool hasAbilita();
    virtual nlohmann::json exportToJSON() const;
};

#endif // POKEMON_H
