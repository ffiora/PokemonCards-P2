#include "model.h"

Container<DeepPtr<Carta> > Model::getMazzo() const
{
    return mazzo;
}

void Model::saveToFile(std::string path) const {
    jsonio::exportToJSON(path,mazzo);
}

void Model::loadFromFile(std::string path) {
    mazzo=jsonio::importFromJson(path);
}

unsigned int Model::count() const{
    return mazzo.size();
}

void Model::remove(unsigned int index) {
    mazzo.erase(index);
}
void Model::add(Carta* c) {
    mazzo.push_back(c);
}

