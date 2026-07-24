# 🚀 Phase 10: Advanced Topics

![Duration](https://img.shields.io/badge/Duration-2_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Advanced-red) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey) ![Optional](https://img.shields.io/badge/Optional-High_Value-purple)

> Optional but high-value — these show up in top-tier interviews and CP contests.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Tries — autocomplete, word search | 🟡 Medium | ☐ |
| 2 | Segment trees | 🟡 Medium | ☐ |
| 3 | Fenwick tree (Binary Indexed Tree) | 🟡 Medium | ☐ |
| 4 | Sliding window maximum | 🔴 High | ☐ |
| 5 | Monotonic deque | 🟡 Medium | ☐ |
| 6 | Z-function | 🟢 Low | ☐ |
| 7 | Rabin-Karp | 🟢 Low | ☐ |

## 🧠 Key Concepts

- **Segment Tree** — O(log n) range query + update, more flexible than Fenwick tree
- **Fenwick Tree (BIT)** — simpler to code, great for prefix sum queries with updates
- **Trie** — O(L) insert/search where L = word length, base for autocomplete systems

## 💻 Important Code Snippets

### Trie Implementation
```cpp
struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
};
```

### Segment Tree — Range Sum + Point Update
```cpp
class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) +
               query(2*node+1, mid+1, end, l, r);
    }
};
```

### Fenwick Tree / BIT — Prefix Sum with Updates
```cpp
class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & (-i))
            bit[i] += delta;
    }
    int query(int i) {  // prefix sum [1..i]
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }
};
```

### Sliding Window Maximum — Monotonic Deque
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // stores indices
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}
```

## 📈 Problem Distribution (20 problems)

```
Tries              [██████░░░░] 25%
Segment Tree/BIT   [████████░░] 35%
Sliding Window Max [█████░░░░░] 20%
String Algorithms  [████░░░░░░] 20%
```

## ✅ Practice Checklist

- [ ] Implement Trie — insert, search, startsWith
- [ ] Build segment tree — range sum + point update
- [ ] Implement Fenwick tree
- [ ] Sliding window maximum using monotonic deque
- [ ] Z-function based pattern matching
- [ ] Rabin-Karp string matching

## ⬅️ Navigation

**[← Phase 9: Greedy Algorithms](./PHASE_9_GREEDY.md)** | **[🏠 Back to Main Roadmap](./README.md)**

---

🎉 **Congrats on reaching the final phase!** Time to start mixed revision + contest practice.
