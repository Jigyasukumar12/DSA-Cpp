// ============================================================
// Phase 6: Heaps & Hashing
// Topics: kth largest, top-K frequent, two-sum,
//         group anagrams, manual heapify
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Kth Largest Element — Min-Heap ----------
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// ---------- Top-K Frequent Elements ----------
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (auto& [val, count] : freq) {
        pq.push({count, val});
        if ((int)pq.size() > k) pq.pop();
    }
    vector<int> res;
    while (!pq.empty()) { res.push_back(pq.top().second); pq.pop(); }
    return res;
}

// ---------- Two Sum — Hashmap ----------
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}

// ---------- Group Anagrams ----------
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

// ---------- Build a Max-Heap Manually (Heapify) ----------
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
    int n = (int)arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << "2nd largest: " << findKthLargest(nums, 2) << "\n";

    vector<int> freqNums = {1,1,1,2,2,3};
    auto topK = topKFrequent(freqNums, 2);
    for (int x : topK) cout << x << " ";
    cout << "\n";

    vector<int> arrTwoSum = {2, 7, 11, 15};
    auto res = twoSum(arrTwoSum, 9);
    cout << "Two sum indices: " << res[0] << " " << res[1] << "\n";

    buildHeap(nums);
    cout << "Max after heapify: " << nums[0] << "\n";

    return 0;
}
