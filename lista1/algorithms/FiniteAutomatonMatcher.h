//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_FINITEAUTOMATONMATCHER_H
#define LISTA1_FINITEAUTOMATONMATCHER_H


#include <functional>
#include <utility>
#include <vector>
#include <memory>
#include <codecvt>
#include <locale>
#include <utility>

#include "PatternMatcher.h"

class FiniteAutomatonMatcher {
public:
    explicit FiniteAutomatonMatcher(std::shared_ptr<PatternMatcher> matcher) {
        this->matcher = std::move(matcher);
    }

    std::shared_ptr<std::vector<int>> matchPattern(const std::wstring &text);
private:
    std::shared_ptr<PatternMatcher> matcher;
};


#endif //LISTA1_FINITEAUTOMATONMATCHER_H
