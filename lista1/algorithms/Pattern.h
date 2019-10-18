//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_PATTERN_H
#define LISTA1_PATTERN_H


#include <string>
#include <functional>
#include <vector>
#include <map>

using functionMap = std::map<int, std::map<char, int>>;

class Pattern {
public:
    explicit Pattern(const std::string &alphabet) : alphabet(alphabet) {};

    std::function<int(int, char)> &match(const std::string &pattern);

private:
    const std::vector<functionMap&> functions;
    const std::string &alphabet;

    inline bool ends_with(const std::string &text, const std::string &suffix);
};


#endif //LISTA1_PATTERN_H
