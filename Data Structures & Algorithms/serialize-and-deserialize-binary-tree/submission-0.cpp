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
 #include <string>

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string res;
         dfs_serialize(root, res);
         cout << res;
         return res;
    }

    void dfs_serialize(TreeNode* root, string& res) {
        if (!root) {
            res += "N,";
            return;
        }
        res += to_string(root->val) + ",";
        dfs_serialize(root->left, res);
        dfs_serialize(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return dfs_deserialize(data, index);
    }

    TreeNode* dfs_deserialize(string data, int& index) {
        if (index >= data.length()) return {};
        if (data[index] == 'N') {
            index += 2;
            return nullptr;
        }
        int val = 0;
        size_t increment;
        val += stoi(data.substr(index, data.length() - index), &increment);
        TreeNode* root = new TreeNode(val);
        index += increment + 1;
        root->left = dfs_deserialize(data, index);
        root->right = dfs_deserialize(data, index);
        return root;
    }
};
