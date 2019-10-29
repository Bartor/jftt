package algorithms.automaton

import algorithms.PatternMatcherInterface

class AutomatonPatternMatcher : PatternMatcherInterface {
    public override fun findMatches(text: String, pattern: String): List<Int> {
        TransitionFunctionFactory(text.toList().distinct().joinToString("")).also {
            return FiniteAutomatonMatcher().match(text, it.match(pattern))
        }
    }

    override fun toString(): String {
        return "APM"
    }
}