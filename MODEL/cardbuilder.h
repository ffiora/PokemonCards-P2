#ifndef CARDBUILDER_H
#define CARDBUILDER_H
#include "JSON/json.hpp"
#include "MODEL/pokemon.h"
#include "MODEL/energia.h"
#include "MODEL/allenatore.h"


class CardBuilder{
private:
    static std::vector<std::string> jArrayToVector(const nlohmann::json&);
public:
    virtual ~CardBuilder()=0;
    static Pokemon* pkBuilder(const nlohmann::json & );
    static Energia* enBuilder(const nlohmann::json & );
    static Allenatore* alBuilder(const nlohmann::json & );
};

#endif // CARDBUILDER_H
