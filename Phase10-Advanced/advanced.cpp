// ============================================================
// Phase 10: Advanced Topics
// Topics: Trie, Segment Tree, Fenwick Tree, Sliding Window Max
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Trie ----------
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

// ---------- Segment Tree — Range Sum + Point Update ----------
class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& arr) {
        n = (int)arr.size();
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

// ---------- Fenwick Tree / BIT ----------
class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & (-i))
            bit[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }
};

// ---------- Sliding Window Maximum — Monotonic Deque ----------
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < (int)nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search 'apple': " << (trie.search("apple") ? "yes" : "no") << "\n";
    cout << "Search 'app': " << (trie.search("app") ? "yes" : "no") << "\n";

    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);
    cout << "Range sum [1,3]: " << segTree.query(1, 0, (int)arr.size()-1, 1, 3) << "\n";

    FenwickTree bit((int)arr.size());
    for (int i = 0; i < (int)arr.size(); i++) bit.update(i+1, arr[i]);
    cout << "Prefix sum [1..4]: " << bit.query(4) << "\n";

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = maxSlidingWindow(nums, 3);
    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
