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
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int n) {
        if(n == 1) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        if(dp.find(n) != dp.end()) return dp[n];
        vector<TreeNode*> ans;
        for(int i = 1; i < n; i+=2) {
            int j = n - i - 1;
            vector<TreeNode*> left = solve(i);
            vector<TreeNode*> right = solve(j);
            for(auto& l: left) {
                for(auto& r: right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        return solve(n); 
    }
};