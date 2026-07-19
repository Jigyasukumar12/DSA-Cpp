// ============================================================
// Phase 5: Trees
// Topics: traversals, BST ops, diameter, LCA
// ============================================================
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ---------- Inorder Traversal — Recursive ----------
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

// ---------- Level Order Traversal — BFS ----------
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = (int)q.size();
        vector<int> level;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}

// ---------- BST — Insert, Validate ----------
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

// ---------- Diameter of Binary Tree ----------
int diameter = 0;
int height(TreeNode* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

// ---------- Lowest Common Ancestor ----------
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    TreeNode* root = nullptr;
    for (int v : {50, 30, 70, 20, 40, 60, 80})
        root = insertBST(root, v);

    vector<int> res;
    inorder(root, res);
    cout << "Inorder: ";
    for (int x : res) cout << x << " ";
    cout << "\n";

    cout << "Is valid BST? " << (isValidBST(root) ? "yes" : "no") << "\n";

    height(root);
    cout << "Diameter: " << diameter << "\n";

    auto levels = levelOrder(root);
    cout << "Levels: " << levels.size() << "\n";

    return 0;
}
