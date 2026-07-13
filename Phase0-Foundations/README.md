# 🧱 Phase 0: C++ Foundations

![Duration](https://img.shields.io/badge/Duration-1_Week-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> The base layer. Get comfortable with C++ syntax and STL before touching any algorithm.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Syntax, data types, I/O (`cin`/`cout`) | 🔴 High | ☐ |
| 2 | Fast I/O — `ios_base::sync_with_stdio(false)` | 🔴 High | ☐ |
| 3 | Functions, pass by reference/pointer | 🔴 High | ☐ |
| 4 | Arrays, strings, 2D arrays basics | 🔴 High | ☐ |
| 5 | STL basics: `vector`, `pair`, `string` methods | 🔴 High | ☐ |
| 6 | Time & Space Complexity — Big O | 🔴 High | ☐ |

## 🧠 Key Concepts

- **Best / Worst / Average case** — know the difference before analyzing any algorithm
- **Pass by reference vs pointer** — avoids unnecessary copying, critical for large data
- **`vector`** is your default array — dynamic sizing, contiguous memory

## 💻 Important Code Snippets

### Fast I/O Template
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {5, 3, 8, 1};
    sort(arr.begin(), arr.end());
    for (int x : arr) cout << x << " ";
    return 0;
}
```

### Pass by Reference vs Pointer
```cpp
// Pass by reference — modifies original directly
void increment(int &x) { x++; }

// Pass by pointer — needs dereferencing
void incrementPtr(int *x) { (*x)++; }

int main() {
    int a = 5;
    increment(a);      // a becomes 6
    incrementPtr(&a);  // a becomes 7
}
```

### Common `vector` Operations
```cpp
vector<int> v = {4, 2, 9, 1};
v.push_back(10);              // insert at end
v.pop_back();                 // remove from end
v.insert(v.begin() + 1, 99);  // insert at index 1
v.erase(v.begin());           // remove first element
sort(v.begin(), v.end());     // ascending sort
reverse(v.begin(), v.end());  // reverse in place
int mx = *max_element(v.begin(), v.end());
```

### `pair` & 2D Vector
```cpp
pair<int, int> p = {3, 4};
cout << p.first << " " << p.second;

// 2D vector (matrix) of size n x m initialized to 0
int n = 3, m = 4;
vector<vector<int>> grid(n, vector<int>(m, 0));
```

### `string` Methods
```cpp
string s = "hello world";
s.substr(0, 5);      // "hello"
s.find("world");     // index 6
s + "!";             // concatenation
s.length();           // size
```

## ✅ Practice Checklist

- [ ] Solve 10 basic I/O problems
- [ ] Implement array reversal without STL
- [ ] Write a program using `pair<int,int>`
- [ ] Explain Big O of 3 different loops (nested, single, log)

## ➡️ Next Phase

**[Phase 1: Math + Basic Problem Solving →](/Phase1-Math)**
