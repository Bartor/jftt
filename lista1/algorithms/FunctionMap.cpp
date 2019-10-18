//
// Created by brajczyk on 18.10.2019.
//

#include <memory>
#include "FunctionMap.h"

FunctionMap::FunctionMap() {
    this->mapHandle = std::make_unique<std::map<int, std::shared_ptr<std::map<char, int>>>>();
}

void FunctionMap::set(int state, char input, int output) {
    std::shared_ptr<std::map<char, int>> elementMap;
    try {
        elementMap = this->mapHandle->at(state);
    } catch (std::out_of_range &e) {
        elementMap = std::make_shared<std::map<char, int>>();
        this->mapHandle->insert({state, elementMap});
    }
    elementMap->insert({input, output});
}

int FunctionMap::get(int state, char input) {
    return this->mapHandle->at(state)->at(input);
}
