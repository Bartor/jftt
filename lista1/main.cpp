#include <iostream>
#include <memory>

#include "algorithms/Alphabet.h"
#include "algorithms/FiniteAutomatonMatcher.h"

int main() {
    auto alphabet = L"abcdeąężźć€ł";
    auto toMatch = L"ab";
    auto inText = L"ababababababababbabbcebdebdecabcdebcabdcebcdabc";

    auto pattern = std::make_unique<Alphabet>(alphabet);
    auto text = std::make_unique<FiniteAutomatonMatcher>(pattern->match(toMatch));
    auto result = text->matchPattern(inText);

    for (auto res : *result) {
        std::cout << res << std::endl;
    }

    return 0;
}