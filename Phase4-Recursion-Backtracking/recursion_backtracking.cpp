// ============================================================
// Phase 4: Recursion & Backtracking
// Topics: subsets, permutations, combination sum, N-Queens
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---------- Generate All Subsets ----------
void subsets(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res) {
    if (idx == (int)nums.size()) {
        res.push_back(curr);
        return;
    }
    subsets(nums, idx + 1, curr, res);       // exclude
    curr.push_back(nums[idx]);
    subsets(nums, idx + 1, curr, res);       // include
    curr.pop_back();
}

// ---------- All Permutations ----------
void permute(vector<int>& nums, int idx, vector<vector<int>>& res) {
    if (idx == (int)nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = idx; i < (int)nums.size(); i++) {
        swap(nums[idx], nums[i]);
        permute(nums, idx + 1, res);
        swap(nums[idx], nums[i]);  // backtrack
    }
}

// ---------- Combination Sum ----------
void combinationSum(vector<int>& candidates, int target, int idx,
                     vector<int>& curr, vector<vector<int>>& res) {
    if (target == 0) { res.push_back(curr); return; }
    if (target < 0 || idx == (int)candidates.size()) return;

    curr.push_back(candidates[idx]);
    combinationSum(candidates, target - candidates[idx], idx, curr, res);
    curr.pop_back();

    combinationSum(candidates, target, idx + 1, curr, res);
}

// ---------- N-Queens ----------
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

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> curr;
    vector<vector<int>> subsetRes;
    subsets(nums, 0, curr, subsetRes);
    cout << "Subsets count: " << subsetRes.size() << "\n";

    vector<vector<int>> permRes;
    permute(nums, 0, permRes);
    cout << "Permutations count: " << permRes.size() << "\n";

    vector<int> candidates = {2, 3, 6, 7};
    vector<int> combCurr;
    vector<vector<int>> combRes;
    combinationSum(candidates, 7, 0, combCurr, combRes);
    cout << "Combination sum solutions: " << combRes.size() << "\n";

    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> nQueensRes;
    solveNQueens(board, 0, n, nQueensRes);
    cout << "N-Queens (n=4) solutions: " << nQueensRes.size() << "\n";

    return 0;
}
