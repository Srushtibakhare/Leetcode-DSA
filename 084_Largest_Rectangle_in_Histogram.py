def largestRectangleArea(heights):

    stack = []
    maxArea = 0

    for i, h in enumerate(heights):

        start = i

        while stack and stack[-1][1] > h:

            index, height = stack.pop()

            maxArea = max(maxArea, height * (i - index))

            start = index

        stack.append((start, h))

    n = len(heights)

    while stack:

        index, height = stack.pop()

        maxArea = max(maxArea, height * (n - index))

    return maxArea


heights = [2,1,5,6,2,3]

print("Largest Area =", largestRectangleArea(heights))