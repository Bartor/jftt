package algorithms.automaton

class TransitionFunction(
    public val size: Int
) {
    private val map : MutableMap<Int, MutableMap<Char, Int>> = HashMap()

    public fun setState(state: Int, input: Char, output: Int) {
        var ref = this.map[state]
        if (ref == null) {
            ref = HashMap()
            this.map[state] = ref
        }
        ref[input] = output
    }

    public fun getState(state: Int, input: Char) : Int {
        return this.map.getOrDefault(state, mapOf(' ' to -1)).getOrDefault(input, -1)
    }

    public override fun toString(): String {
        return this.map.toString()
    }
}