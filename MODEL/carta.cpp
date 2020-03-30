#include "carta.h"


Carta::Carta(std::string no, std::string es,std::string nu, std::string ra, std::string se): nome(no), espansione(es), numero(nu), rarita(ra), serie(se){
    posseduta=false;
}

bool Carta::getPosseduta() const
{
    return posseduta;
}

std::string Carta::getNome() const
{
    return nome;
}

std::string Carta::getEspansione() const
{
    return espansione;
}

std::string Carta::getNumero() const
{
    return numero;
}

std::string Carta::getRarita() const
{
    return rarita;
}

std::string Carta::getSerie() const
{
    return serie;
}

void Carta::setEspansione(const std::string &value)
{
    espansione = value;
}

void Carta::setNumero(const std::string &value)
{
    numero = value;
}

void Carta::setRarita(const std::string &value)
{
    rarita = value;
}

void Carta::setSerie(const std::string &value)
{
    serie = value;
}

void Carta::setNome(const std::string &value)
{
    nome = value;
}

void Carta::setPosseduta(bool value)
{
    posseduta=value;
}

nlohmann::json Carta::exportToJSON() const{
    nlohmann::json j;

    j["name"] = nome;
    j["set"] = espansione;
    j["number"] = numero;
    j["rarity"] = rarita;
    j["series"] = serie;
    if(posseduta) j["owned"]=true;

    return j;
}

