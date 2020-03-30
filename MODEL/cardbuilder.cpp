#include "cardbuilder.h"

std::vector<std::string> CardBuilder::jArrayToVector(const nlohmann::json &a) {
    std::vector<std::string> elems;
    for (const auto& e : a){
        elems.push_back(e.get<std::string>());
    }
    return elems;
}

Pokemon* CardBuilder::pkBuilder(const nlohmann::json & pkdata){

    Pokemon* pk=new Pokemon(pkdata["name"].get<std::string>(),
            pkdata["set"].get<std::string>(),
            pkdata["number"].get<std::string>() ,
            pkdata["rarity"].get<std::string>() ,
            pkdata["series"].get<std::string>() ,
            pkdata["nationalPokedexNumber"].get<unsigned int>(),
            pkdata["subtype"].get<std::string>(),
            static_cast<unsigned int>(std::stoi(pkdata["hp"].get<std::string>()))
            );
    try{
        if(pkdata.contains("owned")) pk->setPosseduta(pkdata["owned"]);
        if(pkdata.contains("evolvesFrom")) pk->setEvolveDa(pkdata["evolvesFrom"].get<std::string>());
        if(pkdata.contains("convertedRetreatCost")) pk->setCostoRitirata(static_cast<unsigned int>(pkdata["convertedRetreatCost"].get<int>()));
        else pk->setCostoRitirata(0);
        if(pkdata.contains("text")) pk->setRegole(jArrayToVector(pkdata["text"]));
        if(pkdata.contains("weaknesses")){
            for (const auto& w : pkdata["weaknesses"]){
                pk->addDeb(w["type"].get<std::string>(),w["value"].get<std::string>());
            }
         }
        if(pkdata.contains("resistances")) {
            for (const auto& r : pkdata["resistances"]){
                pk->addRes(r["type"].get<std::string>(),r["value"].get<std::string>());
            }
        }
        if(pkdata.contains("attacks")) {
            for (const auto& a : pkdata["attacks"]){
                pk->addMossa(a["name"].get<std::string>(),a["damage"].get<std::string>(),a["text"].get<std::string>(),jArrayToVector(a["cost"]));
            }
        }
        if(pkdata.contains("ability")) {
                 pk->setAbilita(pkdata["ability"]["name"].get<std::string>(),pkdata["ability"]["text"].get<std::string>(),pkdata["ability"]["type"].get<std::string>());
        }
    }
    catch(...){

    }

    pk->setTipi(jArrayToVector(pkdata["types"]));
    return pk;
}


Energia* CardBuilder::enBuilder(const nlohmann::json & endata){
    Energia* en;
    if(endata["subtype"].get<std::string>()=="special"){
        en= new Energia(endata["name"].get<std::string>(),
        endata["set"].get<std::string>(),
        endata["number"].get<std::string>(),
        endata["rarity"].get<std::string>(),
        endata["series"].get<std::string>(),
        endata["text"][0].get<std::string>(),
        true);
    }
    else {
        en= new Energia(endata["name"].get<std::string>(),
        endata["set"].get<std::string>(),
        endata["number"].get<std::string>(),
        endata["rarity"].get<std::string>(),
        endata["series"].get<std::string>(),
        endata["name"].get<std::string>(),
        false);
    }
    if(endata.contains("owned")) en->setPosseduta(endata["owned"]);
    return en;
}


Allenatore* CardBuilder::alBuilder(const nlohmann::json & aldata){
    Allenatore* al= new Allenatore(aldata["name"].get<std::string>() ,
            aldata["set"].get<std::string>() ,
            aldata["number"].get<std::string>() ,
            aldata["rarity"].get<std::string>() ,
            aldata["series"].get<std::string>() ,
            aldata["text"][0].get<std::string>() ,
            aldata["subtype"].get<std::string>() );
    if(aldata.contains("owned")) al->setPosseduta(aldata["owned"]);
    return al;
}


