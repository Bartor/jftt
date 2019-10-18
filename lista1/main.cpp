#include <iostream>
#include <memory>
#include "algorithms/Pattern.h"
#include "algorithms/FiniteAutomatonMatcher.h"

int main() {
    auto pattern = std::make_unique<Pattern>("abced");
    auto text = std::make_unique<FiniteAutomatonMatcher>(pattern->match("ab"));

    auto result = text->matchPattern("abcedebcebabcebdbceb");

    for (auto res : *result) {
        std::cout << res << std::endl;
    }

    return 0;
}