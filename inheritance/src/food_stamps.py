"""
Food Stamps Problem

Approach: Binary Search on Answer + Mathematical Calculation

Why Binary Search?
- M can be up to 10^9, so we can't simulate each purchase
- We binary search on the minimum taste point threshold 'x'
- For a given threshold x, calculate how many purchases give >= x points

For food i with value v[i] and decay d[i]:
- k-th purchase gives: v[i] - d[i] * (k-1) points
- We want: v[i] - d[i] * (k-1) >= x
- Solving: k <= (v[i] - x) / d[i] + 1
- So max purchases above threshold x: floor((v[i] - x) / d[i]) + 1 (if v[i] >= x)

Sum of taste points for k purchases of food i:
Sum = v[i] + (v[i]-d[i]) + (v[i]-2*d[i]) + ... + (v[i]-(k-1)*d[i])
    = k * v[i] - d[i] * (0 + 1 + 2 + ... + (k-1))
    = k * v[i] - d[i] * k * (k-1) / 2
"""


def count_purchases(n, v, d, threshold):
    """Count total purchases possible with taste points >= threshold"""
    count = 0
    for i in range(n):
        if v[i] >= threshold:
            count += (v[i] - threshold) // d[i] + 1
    return count


def calculate_sum(n, v, d, threshold):
    """Calculate total taste points for all purchases >= threshold"""
    total = 0
    for i in range(n):
        if v[i] >= threshold:
            k = (v[i] - threshold) // d[i] + 1  # number of purchases
            # Sum = k*v[i] - d[i]*k*(k-1)/2
            total += k * v[i] - d[i] * k * (k - 1) // 2
    return total


def solve(n, m, v, d):
    """
    Main solving function using binary search

    Args:
        n: number of food types
        m: maximum meals allowed
        v: list of initial taste points for each food
        d: list of decay values for each food

    Returns:
        Maximum taste points achievable
    """
    # Binary search on the minimum taste point threshold
    left, right = 0, 10**9 + 7
    min_threshold = 0

    # Find the minimum threshold where we can still make <= m purchases
    while left <= right:
        mid = left + (right - left) // 2
        purchases = count_purchases(n, v, d, mid)

        if purchases <= m:
            min_threshold = mid
            right = mid - 1  # Try lower threshold to get more purchases
        else:
            left = mid + 1   # Need higher threshold to reduce purchases

    # Calculate sum for all purchases >= min_threshold
    total_sum = calculate_sum(n, v, d, min_threshold)
    total_purchases = count_purchases(n, v, d, min_threshold)

    # If we have room for more purchases, fill them with (min_threshold - 1) points
    # But only if min_threshold > 0
    if total_purchases < m and min_threshold > 0:
        remaining = m - total_purchases
        total_sum += remaining * (min_threshold - 1)

    return total_sum


def main():
    # Read input
    try:
        n = int(input())
        m = int(input())

        v = []
        for _ in range(n):
            v.append(int(input()))

        d = []
        for _ in range(n):
            d.append(int(input()))

        result = solve(n, m, v, d)
        print(result)
    except (EOFError, ValueError):
        pass


if __name__ == "__main__":
    main()


"""
Test Case Walkthrough (Case 3):
Input: n=3, m=5
       v = [5, 7, 9]
       d = [2, 4, 6]

Binary Search finds threshold = 3

For threshold = 3:
- Food 0: (5-3)/2 + 1 = 2 purchases, sum = 2*5 - 2*2*1/2 = 10 - 2 = 8
- Food 1: (7-3)/4 + 1 = 2 purchases, sum = 2*7 - 4*2*1/2 = 14 - 4 = 10
- Food 2: (9-3)/6 + 1 = 2 purchases, sum = 2*9 - 6*2*1/2 = 18 - 6 = 12

Total purchases = 6, but m = 5, so threshold too low

For threshold = 4:
- Food 0: (5-4)/2 + 1 = 1 purchase, sum = 5
- Food 1: (7-4)/4 + 1 = 1 purchase, sum = 7
- Food 2: (9-4)/6 + 1 = 1 purchase, sum = 9

Total = 3 purchases, need 2 more at threshold-1 = 3 points each
Final = 5 + 7 + 9 + 3 + 3 = 27 ✓
"""
