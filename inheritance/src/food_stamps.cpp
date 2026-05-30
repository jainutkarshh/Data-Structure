/*
 * Food Stamps Problem
 *
 * Approach: Binary Search on Answer + Mathematical Calculation
 *
 * Why Binary Search?
 * - M can be up to 10^9, so we can't simulate each purchase
 * - We binary search on the minimum taste point threshold 'x'
 * - For a given threshold x, calculate how many purchases give >= x points
 *
 * For food i with value v[i] and decay d[i]:
 * - k-th purchase gives: v[i] - d[i] * (k-1) points
 * - We want: v[i] - d[i] * (k-1) >= x
 * - Solving: k <= (v[i] - x) / d[i] + 1
 * - So max purchases above threshold x: floor((v[i] - x) / d[i]) + 1 (if v[i] >= x)
 *
 * Sum of taste points for k purchases of food i:
 * Sum = v[i] + (v[i]-d[i]) + (v[i]-2*d[i]) + ... + (v[i]-(k-1)*d[i])
 *     = k * v[i] - d[i] * (0 + 1 + 2 + ... + (k-1))
 *     = k * v[i] - d[i] * k * (k-1) / 2
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Calculate total purchases possible with taste points >= threshold
ll countPurchases(ll n, const vector<ll>& v, const vector<ll>& d, ll threshold) {
    ll count = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i] >= threshold) {
            count += (v[i] - threshold) / d[i] + 1;
        }
    }
    return count;
}

// Calculate total taste points for all purchases >= threshold
ll calculateSum(ll n, const vector<ll>& v, const vector<ll>& d, ll threshold) {
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i] >= threshold) {
            ll k = (v[i] - threshold) / d[i] + 1;  // number of purchases
            // Sum = k*v[i] - d[i]*k*(k-1)/2
            sum += k * v[i] - d[i] * k * (k - 1) / 2;
        }
    }
    return sum;
}

ll solve(ll n, ll m, const vector<ll>& v, const vector<ll>& d) {
    // Binary search on the minimum taste point threshold
    ll left = 0, right = 1e9 + 7;
    ll minThreshold = 0;

    // Find the minimum threshold where we can still make <= m purchases
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll purchases = countPurchases(n, v, d, mid);

        if (purchases <= m) {
            minThreshold = mid;
            right = mid - 1;  // Try lower threshold to get more purchases
        } else {
            left = mid + 1;   // Need higher threshold to reduce purchases
        }
    }

    // Calculate sum for all purchases >= minThreshold
    ll totalSum = calculateSum(n, v, d, minThreshold);
    ll totalPurchases = countPurchases(n, v, d, minThreshold);

    // If we have room for more purchases, fill them with (minThreshold - 1) points
    // But only if minThreshold > 0
    if (totalPurchases < m && minThreshold > 0) {
        ll remaining = m - totalPurchases;
        totalSum += remaining * (minThreshold - 1);
    }

    return totalSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;

    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<ll> v(n), d(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> d[i];
    }

    cout << solve(n, m, v, d) << endl;

    return 0;
}

/*
 * Test Case Walkthrough (Case 3):
 * Input: n=3, m=5
 *        v = [5, 7, 9]
 *        d = [2, 4, 6]
 *
 * Binary Search finds threshold = 3
 *
 * For threshold = 3:
 * - Food 0: (5-3)/2 + 1 = 2 purchases, sum = 2*5 - 2*2*1/2 = 10 - 2 = 8
 * - Food 1: (7-3)/4 + 1 = 2 purchases, sum = 2*7 - 4*2*1/2 = 14 - 4 = 10
 * - Food 2: (9-3)/6 + 1 = 2 purchases, sum = 2*9 - 6*2*1/2 = 18 - 6 = 12
 *
 * Total purchases = 6, but m = 5, so threshold too low
 *
 * For threshold = 4:
 * - Food 0: (5-4)/2 + 1 = 1 purchase, sum = 5
 * - Food 1: (7-4)/4 + 1 = 1 purchase, sum = 7
 * - Food 2: (9-4)/6 + 1 = 1 purchase, sum = 9
 *
 * Total = 3 purchases, need 2 more at threshold-1 = 3 points each
 * Final = 5 + 7 + 9 + 3 + 3 = 27 ✓
 */
