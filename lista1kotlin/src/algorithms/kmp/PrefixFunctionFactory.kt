package algorithms.kmp

class PrefixFunctionFactory {
    public fun computePrefixFunction(pattern: String) : PrefixFunction {
        val fn = PrefixFunction(pattern)
        fn[0] = -1
        var k = -1
        for (q in 1 until pattern.length) {
            while (k > -1 && pattern[k + 1] != pattern[q]) {
                k = fn[k]
            }
            if (pattern[k + 1] == pattern[q]){
                k++
            }
            fn[q] = k
        }
        return fn
    }
}