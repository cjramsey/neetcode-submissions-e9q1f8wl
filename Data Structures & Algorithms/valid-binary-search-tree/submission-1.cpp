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
    bool isValidBST(TreeNode* root) {
        return validate(root, std::numeric_limits<int>::min(),
                        std::numeric_limits<int>::max());
    }

    bool validate(TreeNode* root, int min, int max) {
        if (!root) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        return (validate(root->left, min, root->val) 
                && validate(root->right, root->val, max));
    }
};
