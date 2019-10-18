//
// Created by brajczyk on 18.10.2019.
//

#include "FiniteAutomatonMatcher.h"

int FiniteAutomatonMatcher::matchPatter(const std::string &text, const std::string &pattern) {
    int state = 0;
    for (auto currentSymbol : text) {
        state = this->transitionFn(state, currentSymbol);
        if ()
    }
}
