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
 #include <iterator>

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
        int p_l, int p_r, int i_l, int i_r) {
        // right indexes are exclusive
        if (p_l >= p_r) {
            return {};
        }

        TreeNode* root = new TreeNode(preorder[p_l]);

        int pivot;
        for (int i = i_l; i < i_r; ++i) {
            if (inorder[i] == preorder[p_l]) {
                pivot = i;
                break;
            } 
        }
        root->left = helper(preorder, inorder, p_l + 1, p_l + pivot - i_l + 1, i_l, pivot);
        root->right = helper(preorder, inorder, p_l + pivot - i_l + 1, p_r, pivot + 1, i_r);

        return root;
    }
};
