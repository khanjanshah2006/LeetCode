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

    void solve(TreeNode* root, vector<int>& arr) {
        if(root == nullptr) return;
        if(root -> left == nullptr && root->right == nullptr) {
            arr.push_back(root->val);
            return;
        }
        solve(root->left, arr);
        solve(root->right, arr);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        solve(root1, tree1);
        solve(root2, tree2);
        return (tree1 == tree2);
    }
};