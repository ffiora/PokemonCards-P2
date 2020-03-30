#include "pokemon.h"

//costruttori
Pokemon::Pokemon(std::string no, std::string es,std::string nu, std::string ra, std::string se,
                 unsigned int np, std::string st,unsigned int p):
                 Carta(no,es,nu,ra,se),
                 numeroPokedex(np),pv(p), sottotipo(st)
{
    costoRitirata=0;
}
Pokemon::Mossa::Mossa(std::vector<std::string> co,std::string nm,std::string da,std::string tm):nome(nm),danno(da),testo(tm),costo(co){}

Pokemon::DebRes::DebRes(std::string ti,std::string va): tipo(ti),valore(va){}
//get

unsigned int Pokemon::getPv() const
{
    return pv;
}

unsigned int Pokemon::getNumeroPokedex() const
{
    return numeroPokedex;
}

unsigned int Pokemon::getCostoRitirata() const
{
    return costoRitirata;
}

std::string Pokemon::getEvolveDa() const
{
    return evolveDa;
}

std::string Pokemon::getSottotipo() const
{
    return sottotipo;
}

std::vector<Pokemon::Mossa> Pokemon::getMosse() const
{
    return mosse;
}

std::vector<std::string> Pokemon::getRegole() const
{
    return regole;
}

std::vector<Pokemon::DebRes> Pokemon::getDebolezze() const
{
    return debolezze;
}

std::vector<Pokemon::DebRes> Pokemon::getResistenze() const
{
    return resistenze;
}

std::vector<std::string> Pokemon::getTipi() const
{
    return tipi;
}
std::string Pokemon::getNomeAbilita() const
{
    return nomeAbilita;
}

std::string Pokemon::getTestoAbilita() const
{
    return testoAbilita;
}

std::string Pokemon::getTipoAbilita() const
{
    return tipoAbilita;
}
std::string Pokemon::DebRes::getTipo() const
{
    return tipo;
}

std::string Pokemon::DebRes::getValore() const
{
    return valore;
}

std::string Pokemon::Mossa::getNome() const
{
    return nome;
}

std::string Pokemon::Mossa::getDanno() const
{
    return danno;
}

std::vector<std::string> Pokemon::Mossa::getCosto() const
{
    return costo;
}

std::string Pokemon::Mossa::getTesto() const
{
    return testo;
}


//set
void Pokemon::setCostoRitirata(unsigned int value)
{
    costoRitirata = value;
}

void Pokemon::setEvolveDa(const std::string &value)
{
    evolveDa = value;
}
void Pokemon::setTipiConPos(const std::string &value,unsigned int pos)
{
    tipi[pos]= value;
}

void Pokemon::setRegole(const std::vector<std::string> &value)
{
    regole = value;
}
void Pokemon::setNumeroPokedex(unsigned int value)
{
    numeroPokedex = value;
}

void Pokemon::setSottotipo(const std::string &value)
{
    sottotipo = value;
}

void Pokemon::setPv(unsigned int value)
{
    pv = value;
}

void Pokemon::setTipi(const std::vector<std::string> &value)
{
    tipi = value;
}

void Pokemon::setNomeAbilita(const std::string &value)
{
    nomeAbilita = value;
}

void Pokemon::setTestoAbilita(const std::string &value)
{
    testoAbilita = value;
}

void Pokemon::setTipoAbilita(const std::string &value)
{
    tipoAbilita = value;
}

void Pokemon::setAbilita(std::string n, std::string te, std::string ti)
{
    setNomeAbilita(n);
    setTipoAbilita(ti);
    setTestoAbilita(te);

}
void Pokemon::setDebolezze(const std::vector<DebRes> &value)
{
    debolezze = value;
}

void Pokemon::setResistenze(const std::vector<DebRes> &value)
{
    resistenze = value;
}
void Pokemon::Mossa::setCosto(const std::vector<std::string> &value)
{
    costo = value;
}

//add
void Pokemon::addMossa(std::string no,std::string da,std::string te,std::vector<std::string> co){
    mosse.push_back(Mossa(co,no,da,te));
}


void Pokemon::addRegola(std::string s)
{
    regole.push_back(s);
}

void Pokemon::addDeb(std::string ti,std::string va){
    debolezze.push_back(DebRes(ti,va));

}

void Pokemon::addRes(std::string ti,std::string va){
    resistenze.push_back(DebRes(ti,va));
}
//modifica
void Pokemon::modificaMossa(std::string no,std::string da,std::string te,std::vector<std::string> co,std::string s)
{
    for (std::vector<Mossa>::iterator it=mosse.begin();it!=mosse.end();it++) {
        if((it->nome)==s) {
            it->nome=no;
            it->danno=da;
            it->testo=te;
            it->costo=co;
        }
    }
}
void Pokemon::modificaRegola(std::string nuova, std::string vecchia)
{
    for (std::vector<std::string>::iterator it=regole.begin();it!=regole.end();it++) {
        if((*it)==vecchia) {
            *it=nuova;
            it--;
        }
    }
}
//cerca
Pokemon::Mossa Pokemon::cercaMossa(std::string m) const
{
    for(auto it:mosse){
        if(it.getNome()==m) return it;
    }
}
std::string Pokemon::cercaRegola(std::string r) const
{
    for(auto it:regole){
        if(it==r) return it;
    }
}
//elimina
void Pokemon::eliminaMossa(std::string s)
{
    for (std::vector<Mossa>::iterator it=mosse.begin();it!=mosse.end();it++) {
        if(it->getNome()==s) {
            it=mosse.erase(it);
            it--;
        }
    }
}
void Pokemon::eliminaRegola(std::string s)
{
    for (std::vector<std::string>::iterator it=regole.begin();it!=regole.end();it++) {
        if((*it)==s) {
            it=regole.erase(it);
            it--;
        }
    }
}
//
void Pokemon::togliAbilita()
{
    setNomeAbilita("");
    setTipoAbilita("");
    setTestoAbilita("");

}
bool Pokemon::hasAbilita()
{
    if(nomeAbilita=="") return false;
    else return true;
}
Pokemon* Pokemon::clone () const{
    return new Pokemon(*this);
}
nlohmann::json Pokemon::exportToJSON() const{
    nlohmann::json j=this->Carta::exportToJSON();
    j["supertype"]="Pokémon";
    j["nationalPokedexNumber"] = numeroPokedex;
    j["subtype"] = sottotipo;
    j["convertedRetreatCost"] = costoRitirata;
    j["hp"] = std::to_string(pv);
    j["evolvesFrom"] = evolveDa;
    j["ability"]["name"] = nomeAbilita;
    j["ability"]["text"] = testoAbilita;
    j["ability"]["type"] = tipoAbilita;
    j["types"] = nlohmann::json::array();
    for (auto it : tipi) {
        j["types"].push_back(it);
    }
    j["text"] = nlohmann::json::array();
    for (auto it : regole) {
        j["text"].push_back(it);
    }
    j["attacks"] = nlohmann::json::array();
    nlohmann::json aux;
    for (auto it : mosse) {
        aux["name"]=it.nome;
        aux["text"]=it.testo;
        aux["damage"]=it.danno;
        aux["cost"] = nlohmann::json::array();
        for (auto i : it.costo) {
            aux["cost"].push_back(i);
        }
        j["attacks"].push_back(aux);
    }
    aux.clear();
    j["weaknesses"]= nlohmann::json::array();
    for (auto it : debolezze) {
        aux["type"]=it.tipo;
        aux["value"]=it.valore;
        j["weaknesses"].push_back(aux);
    }
    aux.clear();
    j["resistances"]= nlohmann::json::array();
    for (auto it : debolezze) {
        aux["type"]=it.tipo;
        aux["value"]=it.valore;
        j["resistances"].push_back(aux);
    }

    return j;
}

