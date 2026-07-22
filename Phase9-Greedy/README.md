# 🎯 Phase 9: Greedy Algorithms

![Duration](https://img.shields.io/badge/Duration-1_Week-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> Locally optimal choices that (provably) lead to a globally optimal solution.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Activity selection | 🔴 High | ☐ |
| 2 | Interval scheduling / merging | 🔴 High | ☐ |
| 3 | Fractional knapsack | 🔴 High | ☐ |
| 4 | Huffman encoding — intro | 🟢 Low | ☐ |

## 🧠 Key Concepts

- **Greedy proof intuition** — exchange argument: swapping any choice with the greedy one never improves the result
- **Sort first, then greedily pick** — most greedy problems start with sorting by some criterion
- Greedy ≠ DP — greedy doesn't reconsider past choices; if that's needed, it's DP instead

## 💻 Important Code Snippets

### Activity Selection — Max Non-Overlapping Intervals
```cpp
int maxActivities(vector<pair<int,int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
        [](auto& a, auto& b) { return a.second < b.second; });
    int count = 1, lastEnd = intervals[0].second;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first >= lastEnd) {
            count++;
            lastEnd = intervals[i].second;
        }
    }
    return count;
}
```

### Merge Intervals
```cpp
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (auto& in : intervals) {
        if (res.empty() || res.back()[1] < in[0])
            res.push_back(in);
        else
            res.back()[1] = max(res.back()[1], in[1]);
    }
    return res;
}
```

### Fractional Knapsack
```cpp
double fractionalKnapsack(int W, vector<pair<int,int>>& items) {  // {value, weight}
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    double totalValue = 0;
    for (auto& [val, wt] : items) {
        if (W >= wt) { totalValue += val; W -= wt; }
        else { totalValue += val * ((double)W / wt); break; }
    }
    return totalValue;
}
```

### Minimum Platforms Problem
```cpp
int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int platforms = 1, maxPlatforms = 1, i = 1, j = 0;
    while (i < arr.size() && j < dep.size()) {
        if (arr[i] <= dep[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}
```

## 📈 Problem Distribution (20 problems)

```
Interval Problems  [██████████] 50%
Knapsack (Greedy)  [██████░░░░] 30%
Misc Greedy        [████░░░░░░] 20%
```

## ✅ Practice Checklist

- [ ] Activity selection / meeting rooms
- [ ] Merge intervals
- [ ] Fractional knapsack
- [ ] Job sequencing with deadlines
- [ ] Minimum platforms problem

## ⬅️➡️ Navigation

**[← Phase 8: Dynamic Programming](./PHASE_8_DYNAMIC_PROGRAMMING.md)** | **[Phase 10: Advanced Topics →](./PHASE_10_ADVANCED.md)**
