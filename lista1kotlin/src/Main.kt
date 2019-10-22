import algorithms.PatternMatcherInterface
import algorithms.automaton.AutomatonPatternMatcher
import algorithms.kmp.KMPPatterMatcher

private data class MatchTest(
    public val text: String,
    public val patterns: List<String>
) {
    override fun toString(): String {
        return "$text : $patterns"
    }
}

fun main() {
    val matchers: List<PatternMatcherInterface> = listOf(AutomatonPatternMatcher(), KMPPatterMatcher())
    val tests: List<MatchTest> = listOf(
        MatchTest("αβαβγβαβαβαβαβγ", listOf("δ", "γδ", "αβ", "αβαβ")),
        MatchTest("tytytąąąąąątytytytytą", listOf("a", "tyt", "ąą", "ytą", "ąty")),
        MatchTest("ąćąćąćąśśśćąćąćąćąćśśśćąćś", listOf("&", "&ś", "ąć", "ś", "śś", "ćąć")),
        MatchTest("roωrrρrωrωrωrrωrろωorrρρo", listOf("ろ", "ろω", "ωrωr", "ρo", "rr", "rρrρ"))
    )

    for (matcher in matchers) {
        println("\n[====$matcher====]")
        for (test in tests) {
            println("==$test==")
            for (pattern in test.patterns) {
                println("$pattern -> ${matcher.findMatches(test.text, pattern)}")
            }
        }
    }
}