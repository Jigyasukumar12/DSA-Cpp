// ============================================================
// Phase 9: Greedy Algorithms
// Topics: activity selection, merge intervals,
//         fractional knapsack, minimum platforms
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Activity Selection ----------
int maxActivities(vector<pair<int,int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
        [](auto& a, auto& b) { return a.second < b.second; });
    int count = 1, lastEnd = intervals[0].second;
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i].first >= lastEnd) {
            count++;
            lastEnd = intervals[i].second;
        }
    }
    return count;
}

// ---------- Merge Intervals ----------
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

// ---------- Fractional Knapsack ----------
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

// ---------- Minimum Platforms Problem ----------
int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int platforms = 1, maxPlatforms = 1, i = 1, j = 0;
    while (i < (int)arr.size() && j < (int)dep.size()) {
        if (arr[i] <= dep[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}

int main() {
    vector<pair<int,int>> intervals = {{1,3},{2,4},{3,5},{0,6}};
    cout << "Max activities: " << maxActivities(intervals) << "\n";

    vector<vector<int>> toMerge = {{1,3},{2,6},{8,10},{15,18}};
    auto merged = mergeIntervals(toMerge);
    for (auto& in : merged) cout << "[" << in[0] << "," << in[1] << "] ";
    cout << "\n";

    vector<pair<int,int>> items = {{60,10},{100,20},{120,30}};
    cout << "Fractional knapsack: " << fractionalKnapsack(50, items) << "\n";

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Min platforms: " << minPlatforms(arr, dep) << "\n";

    return 0;
}
