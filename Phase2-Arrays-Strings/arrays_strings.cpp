// ============================================================
// Phase 2: Arrays & Strings
// Topics: Sliding window, binary search, two pointers,
//         prefix sum, merge sort
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Sliding Window: Longest substring without repeats ----------
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> last;
    int start = 0, maxLen = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (last.count(s[i]) && last[s[i]] >= start)
            start = last[s[i]] + 1;
        last[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

// ---------- Binary Search + Variants ----------
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int firstOccurrence(vector<int>& arr, int target) {
    int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    return (idx < (int)arr.size() && arr[idx] == target) ? idx : -1;
}

// ---------- Two Pointers: Pair sum in sorted array ----------
bool pairSum(vector<int>& arr, int target) {
    int i = 0, j = (int)arr.size() - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) return true;
        else if (sum < target) i++;
        else j--;
    }
    return false;
}

// ---------- Prefix Sum ----------
vector<int> buildPrefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < (int)arr.size(); i++)
        prefix[i + 1] = prefix[i] + arr[i];
    return prefix;
}

// ---------- Merge Sort ----------
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
        temp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = temp[k - l];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";

    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << "Binary search 7 -> index " << binarySearch(arr, 7) << "\n";

    cout << "Pair sum 12? " << (pairSum(arr, 12) ? "yes" : "no") << "\n";

    vector<int> data = {1, 2, 3, 4, 5};
    auto prefix = buildPrefixSum(data);
    cout << "Sum[1..3] = " << (prefix[4] - prefix[1]) << "\n";

    vector<int> toSort = {5, 3, 8, 1, 9, 2};
    mergeSort(toSort, 0, (int)toSort.size() - 1);
    for (int x : toSort) cout << x << " ";
    cout << "\n";

    return 0;
}
