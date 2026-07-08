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

## 💻 Practice Snippet

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

## ✅ Practice Checklist

- [ ] Solve 10 basic I/O problems
- [ ] Implement array reversal without STL
- [ ] Write a program using `pair<int,int>`
- [ ] Explain Big O of 3 different loops (nested, single, log)

## ➡️ Next Phase

**[Phase 1: Math + Basic Problem Solving →](./PHASE_1_MATH.md)**
