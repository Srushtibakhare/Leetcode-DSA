class Solution:
    def maxProduct(self, n: int) -> int:
        digits = list(map(int, str(n)))
        digits.sort()
        return digits[-1] * digits[-2]


if __name__ == "__main__":
    obj = Solution()

    n = 24
    print("Maximum Product =", obj.maxProduct(n))

    n = 99
    print("Maximum Product =", obj.maxProduct(n))