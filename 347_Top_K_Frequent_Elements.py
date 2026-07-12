def topKFrequent(nums, k):

    count = {}

    for num in nums:
        count[num] = count.get(num, 0) + 1

    sorted_items = sorted(count.items(), key=lambda x: x[1], reverse=True)

    answer = []

    for i in range(k):
        answer.append(sorted_items[i][0])

    return answer


nums = [1, 1, 1, 2, 2, 3]
k = 2

print(topKFrequent(nums, k))
