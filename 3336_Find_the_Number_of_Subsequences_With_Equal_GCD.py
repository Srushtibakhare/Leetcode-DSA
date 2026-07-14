from functools import cache
from math import gcd

MOD = 10**9 + 7

def subsequencePairCount(nums):
    n = len(nums)

    @cache
    def dfs(i, g1, g2):
        if i == n:
            return 1 if g1 == g2 and g1 != 0 else 0

        ans = dfs(i + 1, g1, g2)
        ans += dfs(i + 1, gcd(g1, nums[i]), g2)
        ans += dfs(i + 1, g1, gcd(g2, nums[i]))

        return ans % MOD

    return dfs(0, 0, 0)


# Test Cases
nums = [1, 2, 3, 4]
print("Output:", subsequencePairCount(nums))

nums = [10, 20, 30]
print("Output:", subsequencePairCount(nums))

nums = [1, 1, 1, 1]
print("Output:", subsequencePairCount(nums))