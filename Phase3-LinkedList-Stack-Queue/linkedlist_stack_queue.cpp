// ============================================================
// Phase 3: Linked List, Stack, Queue
// Topics: cycle detection, reversal, monotonic stack,
//         balanced parentheses, circular queue
// ============================================================
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ---------- Detect Cycle — Floyd's Algorithm ----------
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// ---------- Reverse a Linked List ----------
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

ListNode* reverseListRec(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// ---------- Balanced Parentheses — Stack ----------
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

// ---------- Next Greater Element — Monotonic Stack ----------
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = (int)arr.size();
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

// ---------- Circular Queue (array-based) ----------
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

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    cout << "Has cycle? " << (hasCycle(head) ? "yes" : "no") << "\n";

    head = reverseList(head);
    for (ListNode* cur = head; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";

    cout << "Valid parens \"{[()]}\": " << (isValid("{[()]}") ? "yes" : "no") << "\n";

    vector<int> arr = {2, 1, 2, 4, 3};
    auto nge = nextGreaterElement(arr);
    for (int x : nge) cout << x << " ";
    cout << "\n";

    return 0;
}
