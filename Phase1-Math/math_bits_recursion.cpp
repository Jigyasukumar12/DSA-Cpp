// ============================================================
// Phase 1: Math + Basic Problem Solving
// Topics: Sieve, GCD/LCM, bit manipulation, recursion basics
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Sieve of Eratosthenes ----------
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; (long long)i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    return isPrime;
}

// ---------- GCD & LCM ----------
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// ---------- Bit Manipulation Essentials ----------
int countSetBits(int n) {
    return __builtin_popcount(n);
}
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
int findSingleNumber(vector<int>& nums) {
    int result = 0;
    for (int x : nums) result ^= x;  // XOR cancels pairs
    return result;
}
void toggleBit(int &n, int pos) { n ^= (1 << pos); }
void setBit(int &n, int pos)    { n |= (1 << pos); }
void clearBit(int &n, int pos)  { n &= ~(1 << pos); }
bool checkBit(int n, int pos)   { return (n >> pos) & 1; }

// ---------- Recursion Basics ----------
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
long long power(long long base, long long exp) {
    if (exp == 0) return 1;
    long long half = power(base, exp / 2);
    return (exp % 2 == 0) ? half * half : half * half * base;
}

int main() {
    auto primes = sieve(30);
    cout << "Primes up to 30: ";
    for (int i = 2; i <= 30; i++) if (primes[i]) cout << i << " ";
    cout << "\n";

    cout << "GCD(12, 18) = " << gcd(12, 18) << "\n";
    cout << "LCM(4, 6) = " << lcm(4, 6) << "\n";

    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number: " << findSingleNumber(nums) << "\n";

    cout << "5! = " << factorial(5) << "\n";
    cout << "2^10 = " << power(2, 10) << "\n";

    return 0;
}
