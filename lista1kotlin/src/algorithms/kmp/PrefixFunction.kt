package algorithms.kmp

class PrefixFunction(
    public val pattern: String
) {
    private val function = HashMap<Int, Int>()

    operator fun get(index: Int) : Int {
        return function[index]!!
    }

    operator fun set(index: Int, value: Int) {
        function[index] = value
    }
}