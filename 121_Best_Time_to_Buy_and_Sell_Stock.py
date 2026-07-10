def maxProfit(prices):
    min_price = prices[0]
    max_profit = 0

    for price in prices:
        if price < min_price:
            min_price = price
        else:
            max_profit = max(max_profit, price - min_price)

    return max_profit


# Test Cases
prices1 = [7, 1, 5, 3, 6, 4]
print("Maximum Profit:", maxProfit(prices1))   # Output: 5

prices2 = [7, 6, 4, 3, 1]
print("Maximum Profit:", maxProfit(prices2))   # Output: 0

prices3 = [2, 4, 1]
print("Maximum Profit:", maxProfit(prices3))   # Output: 2