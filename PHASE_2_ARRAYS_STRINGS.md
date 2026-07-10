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

## 💻 Practice Snippet

```cpp
// Sliding Window — longest substring without repeating chars
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
