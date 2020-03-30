#include "allenatore.h"

Allenatore::Allenatore(std::string no, std::string es,std::string nu, std::string ra, std::string se,std::string te, std::string ti):Carta(no,es,nu,ra,se),testo(te),tipo(ti){}

std::string Allenatore::getTipo() const
{
    return tipo;
}

std::string Allenatore::getTesto() const
{
    return testo;
}

void Allenatore::setTipo(const std::string &value)
{
    tipo = value;
}

void Allenatore::setTesto(const std::string &value)
{
    testo = value;
}

Allenatore* Allenatore::clone () const{
    return new Allenatore(*this);
}

nlohmann::json Allenatore::exportToJSON() const{    
    nlohmann::json j=this->Carta::exportToJSON();
    j["supertype"]="Trainer";
    j["text"] = {testo};
    j["subtype"] = tipo;


    return j;
}
