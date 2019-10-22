//
// Created by brajczyk on 18.10.2019.
//

#ifndef LISTA1_ALPHABET_H
#define LISTA1_ALPHABET_H


#include <string>
#include <functional>
#include <vector>
#include <map>
#include <codecvt>
#include <locale>
#include <utility>

#include "PatternMatcher.h"

class Alphabet {
public:
    Alphabet(const std::wstring alphabet) : alphabet(alphabet) {
        std::wcout << alphabet << std::endl;
    };

    std::shared_ptr<PatternMatcher> match(const std::wstring &pattern);

private:
    std::wstring alphabet;

    inline bool ends_with(const std::wstring &text, const std::wstring &suffix);
};

#endif //LISTA1_ALPHABET_H
