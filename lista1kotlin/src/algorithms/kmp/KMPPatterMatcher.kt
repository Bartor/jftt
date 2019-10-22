package algorithms.kmp

import algorithms.PatternMatcherInterface

class KMPPatterMatcher : PatternMatcherInterface {
    override fun findMatches(text: String, pattern: String): List<Int> {
        PrefixFunctionFactory().also {
            return KnuthMorrisPrattMatcher().match(text, it.computePrefixFunction(pattern))
        }
    }

    override fun toString(): String {
        return "KMP Pattern Matcher@${this.hashCode()}"
    }
}