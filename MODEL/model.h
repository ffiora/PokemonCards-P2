#ifndef MODELLO_H
#define MODELLO_H

#include "container.h"
#include"deepptr.h"
#include "carta.h"
#include "jsonio.h"

using std::string;

class Model {
private:
    Container<DeepPtr<Carta>> mazzo;
public:
    Model() = default;
    ~Model() = default;

    void saveToFile(std::string) const;
    void loadFromFile(std::string);
    unsigned int count() const;
    Container<DeepPtr<Carta> > getMazzo() const;
    void remove(unsigned int);
    void add(Carta* c) ;

};

#endif // MODELLO_H
