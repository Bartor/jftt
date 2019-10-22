package algorithms

interface PatternMatcherInterface {
    public fun findMatches(text: String, pattern: String) : List<Int>
}