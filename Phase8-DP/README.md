# 💎 Phase 8: Dynamic Programming

![Duration](https://img.shields.io/badge/Duration-3_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Advanced-red) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey) ![Priority](https://img.shields.io/badge/Priority-⭐_Highest-important)

> The most interview-critical topic. Slow down here — patterns matter more than problem count.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | 1D DP — Fibonacci, climbing stairs | 🔴 High | ☐ |
| 2 | 1D DP — house robber | 🔴 High | ☐ |
| 3 | 0/1 Knapsack | 🔴 High | ☐ |
| 4 | Unbounded Knapsack | 🔴 High | ☐ |
| 5 | LCS (Longest Common Subsequence) | 🔴 High | ☐ |
| 6 | LIS (Longest Increasing Subsequence) | 🔴 High | ☐ |
| 7 | Edit distance | 🔴 High | ☐ |
| 8 | Palindrome problems | 🟡 Medium | ☐ |
| 9 | DP on grids | 🔴 High | ☐ |
| 10 | DP with bitmasking (intro) | 🟢 Low | ☐ |

## 🧠 Key Concepts

- **Identify state first** — what changes between subproblems? That's your DP state.
- **Memoization → Tabulation** — always solve recursive + memo first, then convert to bottom-up
- **Space optimization** — most 2D DPs can be reduced to O(n) using rolling arrays

## 💻 Important Code Snippets

### 0/1 Knapsack
```cpp
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
```

### Longest Common Subsequence (LCS)
```cpp
int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
```

### Longest Increasing Subsequence — O(n log n)
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
```

### Edit Distance
```cpp
int editDistance(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}
```

### House Robber (1D DP)
```cpp
int rob(vector<int>& nums) {
    int prev = 0, curr = 0;
    for (int x : nums) {
        int temp = max(curr, prev + x);
        prev = curr;
        curr = temp;
    }
    return curr;
}
```

### Coin Change — Unbounded Knapsack
```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c] + 1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

## 📈 Problem Distribution (50+ problems)

```
1D DP           [██████░░░░] 15%
Knapsack Family [████████░░] 20%
LCS/LIS         [████████░░] 20%
Edit Distance   [█████░░░░░] 10%
Grid DP         [███████░░░] 15%
Palindrome DP   [█████░░░░░] 12%
Bitmask DP      [███░░░░░░░] 8%
```

## ✅ Practice Checklist

- [ ] 10 1D DP problems (Fibonacci family, house robber)
- [ ] 0/1 knapsack + 5 variant problems
- [ ] Unbounded knapsack + coin change
- [ ] LCS + 5 variant problems
- [ ] LIS — O(n²) and O(n log n) both
- [ ] Edit distance + 3 similar problems
- [ ] 8 palindrome DP problems
- [ ] Grid DP — unique paths, min path sum
- [ ] 3 bitmask DP problems

## ⬅️➡️ Navigation

**[← Phase 7: Graphs](./PHASE_7_GRAPHS.md)** | **[Phase 9: Greedy Algorithms →](./PHASE_9_GREEDY.md)**
