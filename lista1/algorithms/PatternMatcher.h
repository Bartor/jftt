//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_PATTERNMATCHER_H
#define LISTA1_PATTERNMATCHER_H


#include <memory>
#include <utility>
#include "FunctionMap.h"

class PatternMatcher {
public:
    PatternMatcher(std::shared_ptr<FunctionMap> handle, int length) : mapHandle(std::move(handle)), size(length) {};
    int length();
    int get(int state, char input);

private:
    int size;
    std::shared_ptr<FunctionMap> mapHandle;
};


#endif //LISTA1_PATTERNMATCHER_H
