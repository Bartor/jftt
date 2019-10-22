//
// Created by brajczyk on 18.10.2019.
//

#include <memory>
#include <iostream>
#include "Alphabet.h"
#include "FunctionMap.h"
#include "PatternMatcher.h"

std::shared_ptr<PatternMatcher> Alphabet::match(const std::wstring &pattern) {
    auto map = std::make_shared<FunctionMap>();
    for (auto i = 0; i < pattern.length(); i++) {
        for (auto currentSymbol : this->alphabet) {
            int k = pattern.length() + 1 > i + 2 ? i + 2 : pattern.length() + 1;
            do {
                k--;
            } while (ends_with(pattern.substr(0, k), pattern.substr(0, i) + currentSymbol));
            map->set(i, currentSymbol, k);
        }
    }

    return std::make_shared<PatternMatcher>(map, pattern.length());
}

inline bool Alphabet::ends_with(const std::wstring &text, const std::wstring &suffix) {
    return text.length() >= suffix.length() &&
           0 == text.compare(text.length() - suffix.length(), suffix.length(), suffix);
}
