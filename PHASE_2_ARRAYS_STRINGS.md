# 🧵 Phase 2: Arrays & Strings

![Duration](https://img.shields.io/badge/Duration-2_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Beginner--Intermediate-yellow) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> The most-asked topic in interviews. Master patterns here — they reappear everywhere.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Two pointers | 🔴 High | ☐ |
| 2 | Sliding window | 🔴 High | ☐ |
| 3 | Prefix sum / difference array | 🔴 High | ☐ |
| 4 | Merge sort & quick sort (implement by hand) | 🟡 Medium | ☐ |
| 5 | Binary search + `lower_bound`/`upper_bound` | 🔴 High | ☐ |
| 6 | Pattern matching (KMP intro) | 🟢 Low | ☐ |
| 7 | Anagram / frequency-based problems | 🟡 Medium | ☐ |

## 🧠 Key Concepts

- **Two Pointers** — sorted array pair-sum, removing duplicates
- **Sliding Window** — fixed & variable size, longest/shortest substring problems
- **Binary Search** — not just for sorted arrays; works on any monotonic search space

## 💻 Important Code Snippets

### Sliding Window — Longest Substring Without Repeating Chars
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> last;
    int start = 0, maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (last.count(s[i]) && last[s[i]] >= start)
            start = last[s[i]] + 1;
        last[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}
```

### Binary Search + Variants
```cpp
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// First occurrence using lower_bound
int firstOccurrence(vector<int>& arr, int target) {
    int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    return (idx < arr.size() && arr[idx] == target) ? idx : -1;
}
```

### Two Pointers — Pair Sum in Sorted Array
```cpp
bool pairSum(vector<int>& arr, int target) {
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) return true;
        else if (sum < target) i++;
        else j--;
    }
    return false;
}
```

### Prefix Sum
```cpp
vector<int> buildPrefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        prefix[i + 1] = prefix[i] + arr[i];
    return prefix;
}
// Range sum [l, r] = prefix[r+1] - prefix[l]
```

### Merge Sort
```cpp
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
```

## 📈 Problem Distribution (50+ problems)

```
Two Pointers    [████████░░] 20%
Sliding Window  [████████░░] 20%
Prefix Sum      [██████░░░░] 15%
Sorting         [██████░░░░] 15%
Binary Search   [████████░░] 20%
Strings         [████░░░░░░] 10%
```

## ✅ Practice Checklist

- [ ] 10 two-pointer problems
- [ ] 10 sliding window problems
- [ ] 8 prefix sum problems
- [ ] Implement merge sort & quick sort from scratch
- [ ] 10 binary search variants (search in rotated array, first/last occurrence)
- [ ] 10 string/anagram problems

## ⬅️➡️ Navigation

**[← Phase 1: Math](./PHASE_1_MATH.md)** | **[Phase 3: Linked List, Stack, Queue →](./PHASE_3_LINKEDLIST_STACK_QUEUE.md)**
