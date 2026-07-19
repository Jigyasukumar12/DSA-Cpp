# 🌳 Phase 5: Trees

![Duration](https://img.shields.io/badge/Duration-2_Weeks-blue) ![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow) ![Status](https://img.shields.io/badge/Status-Not_Started-lightgrey)

> Non-linear structures start here. Traversal patterns are the foundation for graphs later.

---

## 📊 Progress

```
Overall  [░░░░░░░░░░] 0%
```

## 🗂️ Topics

| # | Topic | Priority | Done |
|---|-------|----------|------|
| 1 | Traversals — inorder/preorder/postorder (recursive) | 🔴 High | ☐ |
| 2 | Traversals — iterative (using stack) | 🟡 Medium | ☐ |
| 3 | BFS / level order traversal | 🔴 High | ☐ |
| 4 | Tree views — top/bottom/left/right | 🟡 Medium | ☐ |
| 5 | Binary Search Tree — insert/delete/search | 🔴 High | ☐ |
| 6 | Validate BST | 🔴 High | ☐ |
| 7 | Diameter of tree | 🟡 Medium | ☐ |
| 8 | Lowest Common Ancestor (LCA) | 🔴 High | ☐ |
| 9 | Balanced tree check | 🟡 Medium | ☐ |

## 🧠 Key Concepts

- **DFS traversals** — recursive is intuitive; iterative uses an explicit stack
- **BFS** — level order using a queue, base for tree-view problems
- **LCA** — recursive approach: if node splits into left & right subtree, it's the LCA

## 💻 Important Code Snippets

### Inorder Traversal — Recursive
```cpp
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
```

### Level Order Traversal — BFS
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
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
```

### BST — Insert, Search, Validate
```cpp
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
```

### Diameter of Binary Tree
```cpp
int diameter = 0;
int height(TreeNode* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
```

### Lowest Common Ancestor (Binary Tree)
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;      // p and q split here
    return left ? left : right;
}
```

## 📈 Problem Distribution (40 problems)

```
Traversals      [███████░░░] 25%
BFS/Views       [██████░░░░] 20%
BST Ops         [███████░░░] 25%
Diameter/LCA    [███████░░░] 20%
Balance Checks  [██░░░░░░░░] 10%
```

## ✅ Practice Checklist

- [ ] All 3 traversals — recursive + iterative
- [ ] Level order + zigzag level order
- [ ] Top/bottom/left/right view
- [ ] BST insert, delete, search, validate
- [ ] Diameter of binary tree
- [ ] LCA (binary tree + BST versions)
- [ ] Check height-balanced tree

## ⬅️➡️ Navigation

**[← Phase 4: Recursion & Backtracking](./PHASE_4_RECURSION_BACKTRACKING.md)** | **[Phase 6: Heaps & Hashing →](./PHASE_6_HEAPS_HASHING.md)**
