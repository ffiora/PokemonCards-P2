#ifndef CARTA_H
#define CARTA_H
#include "JSON/json.hpp"
#include <string>

class Carta{
private:
    bool posseduta;
    std::string nome;
    std::string espansione;
    std::string numero;
    std::string rarita;
    std::string serie;
public:
    Carta(std::string, std::string,std::string, std::string, std::string);
    virtual ~Carta()=default;
    virtual Carta* clone()const =0;
    std::string getNome() const;
    std::string getEspansione() const;
    std::string getNumero() const;
    std::string getRarita() const;
    std::string getSerie() const;
    bool getPosseduta() const;
    void setNome(const std::string &value);
    void setEspansione(const std::string &value);
    void setNumero(const std::string &value);
    void setRarita(const std::string &value);
    void setSerie(const std::string &value);
    void setPosseduta(bool value);
    virtual nlohmann::json exportToJSON() const;
};

#endif // CARTA_H
