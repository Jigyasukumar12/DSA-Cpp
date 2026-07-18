# 🔗 Phase 3: Linked List, Stack, Queue

![Duration](https://img.shields.io/badge/Duration-1.5_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> Linear data structures with a twist — pointer manipulation is the core skill here.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Singly & doubly linked list basics | 🔴 High | ☐ |
| 2 | Reverse a linked list (iterative + recursive) | 🔴 High | ☐ |
| 3 | Cycle detection — Floyd's algorithm | 🔴 High | ☐ |
| 4 | Stack — balanced parentheses | 🔴 High | ☐ |
| 5 | Stack — next greater element, monotonic stack | 🔴 High | ☐ |
| 6 | Queue — circular queue, deque | 🟡 Medium | ☐ |
| 7 | STL: `stack`, `queue`, `deque` | 🔴 High | ☐ |

## 🧠 Key Concepts

- **Floyd's Cycle Detection** — slow/fast pointer, meet point tells you the cycle start
- **Monotonic Stack** — maintains increasing/decreasing order, O(n) for "next greater/smaller" problems
- **Deque** — insert/delete from both ends in O(1), useful for sliding window max

## 💻 Important Code Snippets

### Detect Cycle — Floyd's Algorithm
```cpp
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### Reverse a Linked List
```cpp
// Iterative
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive
ListNode* reverseListRec(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

### Balanced Parentheses — Stack
```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char,char> match = {{')','('},{']','['},{'}','{'}};
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if (st.empty() || st.top() != match[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}
```

### Next Greater Element — Monotonic Stack
```cpp
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;  // stores indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

### Circular Queue (array-based)
```cpp
class CircularQueue {
    vector<int> q;
    int front, rear, size, capacity;
public:
    CircularQueue(int k) : q(k), front(0), rear(-1), size(0), capacity(k) {}
    bool enqueue(int val) {
        if (size == capacity) return false;
        rear = (rear + 1) % capacity;
        q[rear] = val;
        size++;
        return true;
    }
    bool dequeue() {
        if (size == 0) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
};
```

## 📈 Problem Distribution (30 problems)

```
Linked List     [██████████] 40%
Stack           [████████░░] 35%
Queue           [█████░░░░░] 25%
```

## ✅ Practice Checklist

- [ ] Reverse LL — iterative & recursive both
- [ ] Detect + find start of cycle
- [ ] Merge two sorted linked lists
- [ ] Implement stack using array + using LL
- [ ] 8 monotonic stack problems
- [ ] Implement circular queue from scratch

## ⬅️➡️ Navigation

**[← Phase 2: Arrays & Strings](./Phase2-Arrays-Strings)** | **[Phase 4: Recursion & Backtracking →](./Phase4-Recursion-Backtracking)**
