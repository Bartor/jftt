//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_PATTERN_H
#define LISTA1_PATTERN_H


#include <string>
#include <functional>
#include <vector>
#include <map>
#include "PatternMatcher.h"

using functionMap = std::map<int, std::map<char, int>>;

class Pattern {
public:
    Pattern(const std::string &alphabet) : alphabet(alphabet) {};

    std::shared_ptr<PatternMatcher> match(const std::string &pattern);

private:
    const std::string &alphabet;

    inline bool ends_with(const std::string &text, const std::string &suffix);
};

#endif //LISTA1_PATTERN_H
