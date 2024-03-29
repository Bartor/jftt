//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_FUNCTIONMAP_H
#define LISTA1_FUNCTIONMAP_H


#include <map>

class FunctionMap {
    std::unique_ptr<std::map<int, std::shared_ptr<std::map<wchar_t, int>>>> mapHandle;

public:
    FunctionMap();
    void set(int state, wchar_t input, int output);
    int get(int state, char input);
};

#endif //LISTA1_FUNCTIONMAP_H
