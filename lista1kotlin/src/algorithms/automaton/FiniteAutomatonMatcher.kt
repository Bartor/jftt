package algorithms.automaton

class FiniteAutomatonMatcher {
    public fun match(text: String, pattern: TransitionFunction) : List<Int> {
        val result = mutableListOf<Int>()
        var q = 0
        for (i in 0 until text.length) {
            q = pattern.getState(q, text[i])
            if (q == pattern.size) {
                result.add(i - pattern.size + 1)
            }
        }
        return result.toList()
    }
}