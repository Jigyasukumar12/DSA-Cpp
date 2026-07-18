# 🌀 Phase 4: Recursion & Backtracking

![Duration](https://img.shields.io/badge/Duration-1.5_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> Explore all possibilities, prune early. This phase trains the "recursion tree" mindset for DP later.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Subsets / power set | 🔴 High | ☐ |
| 2 | Permutations | 🔴 High | ☐ |
| 3 | Combinations (combination sum) | 🔴 High | ☐ |
| 4 | N-Queens | 🟡 Medium | ☐ |
| 5 | Sudoku solver | 🟡 Medium | ☐ |
| 6 | Rat in a Maze | 🟡 Medium | ☐ |

## 🧠 Key Concepts

- **Backtracking template** — choose → explore → un-choose
- **Pruning** — cut branches early to avoid wasted recursion
- Every backtracking problem = building a **recursion tree** and traversing it

## 💻 Important Code Snippets

### Generate All Subsets
```cpp
void subsets(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(curr);
        return;
    }
    // exclude
    subsets(nums, idx + 1, curr, res);
    // include
    curr.push_back(nums[idx]);
    subsets(nums, idx + 1, curr, res);
    curr.pop_back();
}
```

### All Permutations
```cpp
void permute(vector<int>& nums, int idx, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        permute(nums, idx + 1, res);
        swap(nums[idx], nums[i]);  // backtrack
    }
}
```

### Combination Sum
```cpp
void combinationSum(vector<int>& candidates, int target, int idx,
                     vector<int>& curr, vector<vector<int>>& res) {
    if (target == 0) { res.push_back(curr); return; }
    if (target < 0 || idx == candidates.size()) return;

    // include candidates[idx] (can reuse)
    curr.push_back(candidates[idx]);
    combinationSum(candidates, target - candidates[idx], idx, curr, res);
    curr.pop_back();

    // exclude candidates[idx]
    combinationSum(candidates, target, idx + 1, curr, res);
}
```

### N-Queens
```cpp
bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}
void solveNQueens(vector<string>& board, int row, int n, vector<vector<string>>& res) {
    if (row == n) { res.push_back(board); return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n, res);
            board[row][col] = '.';  // backtrack
        }
    }
}
```

## 📈 Problem Distribution (25 problems)

```
Subsets/Perm/Comb [██████████] 45%
Grid Backtracking [████████░░] 35%
Constraint Solving [████░░░░░░] 20%
```

## ✅ Practice Checklist

- [ ] Subsets (with & without duplicates)
- [ ] All permutations of an array
- [ ] Combination sum I & II
- [ ] N-Queens — print all solutions
- [ ] Sudoku solver
- [ ] Rat in a Maze — all paths

## ⬅️➡️ Navigation

**[← Phase 3: Linked List, Stack, Queue](./PHASE_3_LINKEDLIST_STACK_QUEUE.md)** | **[Phase 5: Trees →](./PHASE_5_TREES.md)**
