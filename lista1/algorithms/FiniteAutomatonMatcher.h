//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_FINITEAUTOMATONMATCHER_H
#define LISTA1_FINITEAUTOMATONMATCHER_H


#include <functional>

class FiniteAutomatonMatcher {
public:
    explicit FiniteAutomatonMatcher(const std::function<int(int, char)>& transitionFunction) {
        this->transitionFn = transitionFunction;
    }
    int matchPatter(const std::string& text, const std::string& pattern);
private:
    std::function<int(int, char)> transitionFn;
};


#endif //LISTA1_FINITEAUTOMATONMATCHER_H
