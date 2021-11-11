#### [226. Invert Binary Tree](https://leetcode-cn.com/problems/invert-binary-tree/)

Given the `root` of a binary tree, invert the tree, and return *its root*.

**Example 1:**



![img](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```

```C
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    root->right = invertTree(left);
    root->left = invertTree(right);
    return root;
}
```

