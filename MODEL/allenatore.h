#ifndef ALLENATORE_H
#define ALLENATORE_H
#include <string>
#include "carta.h"

class Allenatore: public Carta{
private:
    std::string testo;
    std::string tipo;
public:
    Allenatore(std::string = "", std::string = "",std::string = "", std::string ="", std::string="",std::string ="", std::string="");
    virtual Allenatore* clone() const;
    std::string getTipo() const;
    std::string getTesto() const;
    void setTipo(const std::string &value);
    void setTesto(const std::string &value);
    virtual nlohmann::json exportToJSON() const;
};

#endif // ALLENATORE_H
