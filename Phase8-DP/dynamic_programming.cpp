// ============================================================
// Phase 8: Dynamic Programming
// Topics: knapsack, LCS, LIS, edit distance,
//         house robber, coin change
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- 0/1 Knapsack ----------
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w)
                dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
        }
    }
    return dp[n][W];
}

// ---------- Longest Common Subsequence ----------
int lcs(string& a, string& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? 1 + dp[i-1][j-1]
                                           : max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

// ---------- Longest Increasing Subsequence — O(n log n) ----------
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}

// ---------- Edit Distance ----------
int editDistance(string& a, string& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1]
                                           : 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    return dp[n][m];
}

// ---------- House Robber (1D DP) ----------
int rob(vector<int>& nums) {
    int prev = 0, curr = 0;
    for (int x : nums) {
        int temp = max(curr, prev + x);
        prev = curr;
        curr = temp;
    }
    return curr;
}

// ---------- Coin Change — Unbounded Knapsack ----------
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c] + 1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> wt = {1, 3, 4, 5}, val = {1, 4, 5, 7};
    cout << "Knapsack: " << knapsack(7, wt, val, 4) << "\n";

    string a = "abcde", b = "ace";
    cout << "LCS: " << lcs(a, b) << "\n";

    vector<int> lisArr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lengthOfLIS(lisArr) << "\n";

    string s1 = "horse", s2 = "ros";
    cout << "Edit distance: " << editDistance(s1, s2) << "\n";

    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "House robber max: " << rob(houses) << "\n";

    vector<int> coins = {1, 2, 5};
    cout << "Coin change (11): " << coinChange(coins, 11) << "\n";

    return 0;
}
