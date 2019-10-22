//
// Created by brajczyk on 18.10.2019.
//

#include <memory>
#include "FunctionMap.h"

FunctionMap::FunctionMap() {
    this->mapHandle = std::make_unique<std::map<int, std::shared_ptr<std::map<wchar_t, int>>>>();
}

void FunctionMap::set(int state, wchar_t input, int output) {
    std::shared_ptr<std::map<wchar_t , int>> elementMap;
    try {
        elementMap = this->mapHandle->at(state);
    } catch (std::out_of_range &e) {
        elementMap = std::make_shared<std::map<wchar_t , int>>();
        this->mapHandle->insert({state, elementMap});
    }
    elementMap->insert({input, output});
}

int FunctionMap::get(int state, char input) {
    return this->mapHandle->at(state)->at(input);
}
