package algorithms.kmp

class KnuthMorrisPrattMatcher {
    public fun match(text: String, pattern: PrefixFunction) : List<Int> {
        val result = mutableListOf<Int>()
        var q = 0
        for (i in 0 until text.length) {
            while (q > 0 && pattern.pattern[q] != text[i]) {
                q = pattern[q - 1] + 1
            }
            if (pattern.pattern[q] == text[i]) {
                q++
            }
            if (q == pattern.pattern.length) {
                result.add(i - pattern.pattern.length + 1)
                q = pattern[q - 1] + 1
            }
        }
        return result.toList()
    }
}