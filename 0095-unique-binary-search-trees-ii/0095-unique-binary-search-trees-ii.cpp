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
    map<pair<int,int>,vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int i, int j) {
        if(i > j) return {nullptr};
        if(i == j) {
            TreeNode* root = new TreeNode(i);
            return {root};
        }
        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];
        vector<TreeNode*> result;
        for(int k = i; k <= j; k++) {
            vector<TreeNode*> left = solve(i,k-1);
            vector<TreeNode*> right = solve(k+1,j);
            for(auto& l: left) {
                for(auto& r: right) {
                    TreeNode* root = new TreeNode(k);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return dp[{i,j}] = result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};