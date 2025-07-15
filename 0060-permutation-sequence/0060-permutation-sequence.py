class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        numbers = list(range(1, n + 1))
        k -= 1
        result = ""

        for i in range(n, 0, -1):
            f = math.factorial(i - 1)
            index = k // f
            result += str(numbers[index])
            numbers.pop(index)
            k %= f

        return result
