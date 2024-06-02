class Solution {
    fun generate(numRows: Int): List<List<Int>> {
        val result = mutableListOf(listOf(1))

        repeat(numRows - 1) {
            result += buildList<Int> {
                add(1)
                result.last()
                    .asSequence()
                    .zipWithNext()
                    .forEach { (a, b) -> add(a + b) }
                add(1)
            }
        }

        return result
    }
}