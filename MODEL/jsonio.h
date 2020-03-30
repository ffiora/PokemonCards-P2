#ifndef JSONIO_H
#define JSONIO_H
#include "cardbuilder.h"
#include "container.h"
#include "deepptr.h"
#include "JSON/json.hpp"
#include <fstream>
#include <iostream>


class jsonio
{
public:
    virtual ~jsonio()=0;
    static Container<DeepPtr<Carta>> importFromJson (std::string);
    static void exportToJSON(std::string,Container<DeepPtr<Carta>>);
};

#endif // JSONIO_H
