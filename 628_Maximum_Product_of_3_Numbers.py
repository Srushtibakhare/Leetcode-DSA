def maximumProduct(nums):

    nums.sort()
    n = len(nums)

    product1 = nums[n - 1] * nums[n - 2] * nums[n - 3]
    product2 = nums[0] * nums[1] * nums[n - 1]

    return max(product1, product2)


nums = list(map(int, input("Enter numbers: ").split()))

print("Maximum Product:", maximumProduct(nums))