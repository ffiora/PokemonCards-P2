#ifndef ENERGIA_H
#define ENERGIA_H
#include <string>
#include "carta.h"

class Energia: public Carta{
private:
    std::string testo;
    bool speciale;
public:
    Energia(std::string = "", std::string = "",std::string = "", std::string ="", std::string="",std::string = "",bool = false);
    virtual Energia* clone() const;
    bool getSpeciale() const;
    std::string getTesto() const;
    void setTesto(const std::string &value);
    void setSpeciale(bool value);
    virtual nlohmann::json exportToJSON() const;
};

#endif // ENERGIA_H
