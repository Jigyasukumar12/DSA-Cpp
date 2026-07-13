// ============================================================
// Phase 0: C++ Foundations
// Topics: I/O, functions, vectors, pairs, strings, complexity
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Pass by Reference vs Pointer ----------
void increment(int &x) { x++; }
void incrementPtr(int *x) { (*x)++; }

// ---------- Common vector operations ----------
void vectorOpsDemo() {
    vector<int> v = {4, 2, 9, 1};
    v.push_back(10);              // insert at end
    v.pop_back();                 // remove from end
    v.insert(v.begin() + 1, 99);  // insert at index 1
    v.erase(v.begin());           // remove first element
    sort(v.begin(), v.end());     // ascending sort
    reverse(v.begin(), v.end());  // reverse in place
    int mx = *max_element(v.begin(), v.end());
    cout << "Max element: " << mx << "\n";
}

// ---------- pair & 2D vector ----------
void pairAnd2DVectorDemo() {
    pair<int, int> p = {3, 4};
    cout << p.first << " " << p.second << "\n";

    int n = 3, m = 4;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    grid[1][2] = 5;
}

// ---------- string methods ----------
void stringMethodsDemo() {
    string s = "hello world";
    cout << s.substr(0, 5) << "\n";   // "hello"
    cout << s.find("world") << "\n";  // index 6
    string combined = s + "!";
    cout << combined.length() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {5, 3, 8, 1};
    sort(arr.begin(), arr.end());
    for (int x : arr) cout << x << " ";
    cout << "\n";

    int a = 5;
    increment(a);      // a becomes 6
    incrementPtr(&a);  // a becomes 7
    cout << "a = " << a << "\n";

    vectorOpsDemo();
    pairAnd2DVectorDemo();
    stringMethodsDemo();

    return 0;
}
