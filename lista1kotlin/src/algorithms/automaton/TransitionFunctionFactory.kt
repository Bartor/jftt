package algorithms.automaton

import kotlin.math.min

class TransitionFunctionFactory(
    private val alphabet: String
) {
    public fun match(pattern: String) : TransitionFunction {
        val fn = TransitionFunction(pattern.length)
        for (q in 0..pattern.length) {
            for (character in alphabet) {
                var k = min(pattern.length + 1, q + 2) - 1
                while (!"${pattern.subSequence(0 until q)}$character".endsWith(pattern.subSequence(0 until k))) {
                    k--
                }
                fn.setState(q, character, k)
            }
        }
        return fn
    }
}