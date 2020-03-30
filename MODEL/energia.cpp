#include "energia.h"

bool Energia::getSpeciale() const
{
    return speciale;
}

std::string Energia::getTesto() const
{
    return testo;
}

void Energia::setTesto(const std::string &value)
{
    testo = value;
}

void Energia::setSpeciale(bool value)
{
    speciale = value;
}

Energia::Energia(std::string no, std::string es,std::string nu, std::string ra, std::string se,std::string te, bool sp): Carta(no,es,nu,ra,se),testo(te),speciale(sp){}

Energia* Energia::clone () const{
    return new Energia(*this);
}
nlohmann::json Energia::exportToJSON() const{
    nlohmann::json j=this->Carta::exportToJSON();
    j["supertype"]="Energy";
    j["text"] = {testo};
    j["subtype"] = (speciale==true?"Special":"Basic");


    return j;
}
