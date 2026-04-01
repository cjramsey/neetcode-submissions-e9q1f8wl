/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool unbalanced = false;
        height(root, unbalanced);
        return !unbalanced;
    }
    int height(TreeNode* root, bool& unbalanced) {
        if (!root) {
            return 0;
        }
        int left = height(root->left, unbalanced);
        int right = height(root->right, unbalanced);
        if (abs(left - right) > 1) {
            unbalanced = true;
        }
        return 1 + max(left, right);
    }
};
