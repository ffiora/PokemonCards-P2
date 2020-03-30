#include "jsonio.h"

Container<DeepPtr<Carta>> jsonio::importFromJson (std::string path){
    std::ifstream file(path);
    nlohmann::json j;
    Container<DeepPtr<Carta>> mazzo;//size di json (j["cards"].size())
    if (file.is_open())
    try {
            file >> j;
            std::string stp;
            for (const auto& uj : j["cards"]) {
                stp=uj["supertype"];
                switch (stp.c_str()[0]) {
                case 'E':
                    mazzo.push_back(DeepPtr<Carta>(CardBuilder::enBuilder(uj)));
                    break;
                case 'T':
                    mazzo.push_back(DeepPtr<Carta>(CardBuilder::alBuilder(uj)));
                    break;
                case 'P':
                    mazzo.push_back(DeepPtr<Carta>(CardBuilder::pkBuilder(uj)));
                    break;
                }
            }
        } catch(...) {

        }
    return mazzo;
}

void jsonio::exportToJSON(std::string path,Container<DeepPtr<Carta>> mazzo)  {
        nlohmann::json j=nlohmann::json();
        j["cards"] = nlohmann::json::array();
        for (Container<DeepPtr<Carta>>::iteratore  it=mazzo.begin();it!=mazzo.end();it++) {
            j["cards"].push_back(mazzo[it]->exportToJSON());
        }
        std::ofstream file(path);
        file << j.dump();
}
