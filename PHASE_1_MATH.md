# 🔢 Phase 1: Math + Basic Problem Solving

![Duration](https://img.shields.io/badge/Duration-1_Week-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> Number theory + bit manipulation build the intuition you'll reuse everywhere later

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Prime numbers, GCD/LCM | 🔴 High | ☐ |
| 2 | Sieve of Eratosthenes | 🔴 High | ☐ |
| 3 | Bit manipulation — AND/OR/XOR tricks | 🔴 High | ☐ |
| 4 | Count set bits (`__builtin_popcount`) | 🟡 Medium | ☐ |
| 5 | Recursion fundamentals | 🔴 High | ☐ |
| 6 | Backtracking — intro | 🟡 Medium | ☐ |

## 🧠 Key Concepts

- **Sieve of Eratosthenes** — O(n log log n), precompute primes up to 10^6/10^7
- **XOR trick** — find the single non-repeating element in O(n), O(1) space
- **Recursion** — always define base case first, then trust the recursive step

## 💻 Practice Snippet

```cpp
// Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; (long long)i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    return isPrime;
}
```

## 📈 Problem Distribution

```
Number Theory   [███████░░░] 35%
Bit Manipulation[██████░░░░] 30%
Recursion       [███████░░░] 35%
```

## ✅ Practice Checklist

- [ ] 10 GCD/LCM based problems
- [ ] 10 bit manipulation problems (single number, power of 2, etc.)
- [ ] 15 basic recursion problems
- [ ] Implement sieve and use it in 3 problems

## ⬅️➡️ Navigation

**[← Phase 0: Foundations](./PHASE_0_FOUNDATIONS.md)** | **[Phase 2: Arrays & Strings →](./PHASE_2_ARRAYS_STRINGS.md)**
