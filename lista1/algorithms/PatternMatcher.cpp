//
// Created by brajczyk on 18.10.2019.
//

#include "PatternMatcher.h"

int PatternMatcher::length() {
    return this->size;
}

int PatternMatcher::get(int state, char input) {
    return this->mapHandle->get(state, input);
}