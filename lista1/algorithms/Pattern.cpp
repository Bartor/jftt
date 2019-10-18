//
// Created by brajczyk on 18.10.2019.
//

#include <bits/unique_ptr.h>
#include <bits/shared_ptr.h>
#include "Pattern.h"
#include "FunctionMap.h"

std::function<int(int, char)> &Pattern::match(const std::string &pattern) {
    auto map = std::make_shared<FunctionMap>();
    this->functions.push_back(map);
    for (auto i = 0; i < pattern.length(); i++) {
        for (auto currentSymbol : this->alphabet) {
            int k = pattern.length() + 1 > i + 2 ? i + 2 : pattern.length() + 1;
            do {
                k--;
            } while (ends_with(pattern.substr(0, k), pattern.substr(0, i) + currentSymbol));
            map->set(i, currentSymbol, k);
        }
    }
    //TODO return a function int, char -> int = map.get
}

inline bool Pattern::ends_with(const std::string &text, const std::string &suffix) {
    return text.length() >= suffix.length() &&
           0 == text.compare(text.length() - suffix.length(), suffix.length(), suffix);
}
