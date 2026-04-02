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
    int goodNodes(TreeNode* root) {
        return dfs(root, std::numeric_limits<int>::min());
    }

    int dfs(TreeNode* root, int maxSeen) {
        if (!root) {
            return 0;
        }
        int cur = root->val >= maxSeen ? 1 : 0;
        maxSeen = max(maxSeen, root->val);
        return cur + dfs(root->left, maxSeen) + dfs(root->right, maxSeen); 
    } 
};
