//
// Created by brajczyk on 18.10.2019.
//

#include <iostream>
#include "FiniteAutomatonMatcher.h"

std::shared_ptr<std::vector<int>> FiniteAutomatonMatcher::matchPattern(const std::string &text) {
    auto q = 0;
    auto ret = std::make_shared<std::vector<int>>();
    for (auto i = 0; i < text.length(); i++) {
        q = this->matcher->get(q, text[i]);
        if (q == this->matcher->length()) {
            ret->push_back(i - q);
        }
    }

    return ret;
}
