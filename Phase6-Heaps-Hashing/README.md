# ⛰️ Phase 6: Heaps & Hashing

![Duration](https://img.shields.io/badge/Duration-1_Week-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> Fast lookups and priority-based retrieval — short phase, but high ROI in interviews.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Priority queue / heap operations | 🔴 High | ☐ |
| 2 | Heapify — build heap in O(n) | 🟡 Medium | ☐ |
| 3 | Kth largest / smallest element | 🔴 High | ☐ |
| 4 | Top-K frequent elements | 🔴 High | ☐ |
| 5 | Hashmaps/sets — frequency counting | 🔴 High | ☐ |
| 6 | Two-sum style problems | 🔴 High | ☐ |

## 🧠 Key Concepts

- **Min-heap vs Max-heap** — `priority_queue<int, vector<int>, greater<int>>` for min-heap
- **Kth largest** — maintain a min-heap of size K
- **Hashmap** — O(1) average lookup, backbone of most "find pair/frequency" problems

## 💻 Important Code Snippets

### Kth Largest Element — Min-Heap
```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}
```

### Top-K Frequent Elements
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    // min-heap of {frequency, value}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (auto& [val, count] : freq) {
        pq.push({count, val});
        if (pq.size() > k) pq.pop();
    }
    vector<int> res;
    while (!pq.empty()) { res.push_back(pq.top().second); pq.pop(); }
    return res;
}
```

### Two Sum — Hashmap
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen;  // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

### Group Anagrams
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& [k, v] : groups) res.push_back(v);
    return res;
}
```

### Build a Max-Heap Manually (Heapify)
```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}
```

## 📈 Problem Distribution (25 problems)

```
Heap Operations [████████░░] 35%
Top-K Problems  [███████░░░] 30%
Hashing         [████████░░] 35%
```

## ✅ Practice Checklist

- [ ] Implement heap from scratch (insert, extract-min)
- [ ] Kth largest/smallest — 5 variants
- [ ] Top-K frequent elements
- [ ] Two-sum, four-sum using hashmap
- [ ] Group anagrams
- [ ] Longest consecutive sequence

## ⬅️➡️ Navigation

**[← Phase 5: Trees](https://github.com/Jigyasukumar12/DSA-Cpp/tree/main/Phase5-Trees)** | **[Phase 7: Graphs →](https://github.com/Jigyasukumar12/DSA-Cpp/tree/main/Phase7-Graphs)**
