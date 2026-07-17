from collections import Counter
from itertools import accumulate
from bisect import bisect_right

def gcdValues(nums, queries):
    mx = max(nums)
    cnt = Counter(nums)

    # cntG[i] = number of pairs whose GCD is exactly i
    cntG = [0] * (mx + 1)

    for i in range(mx, 0, -1):
        total = 0

        for j in range(i, mx + 1, i):
            total += cnt[j]
            cntG[i] -= cntG[j]

        cntG[i] += total * (total - 1) // 2

    # Prefix sum of pair counts
    prefix = list(accumulate(cntG))

    # Answer queries using binary search
    answer = []

    for q in queries:
        answer.append(bisect_right(prefix, q))

    return answer


def main():
    nums = [2, 3, 4]
    queries = [0, 2]

    result = gcdValues(nums, queries)

    print("Nums:", nums)
    print("Queries:", queries)
    print("Output:", result)


if __name__ == "__main__":
    main()