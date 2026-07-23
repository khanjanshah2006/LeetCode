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
    unordered_map<long long, int> mp;

    int dfs(TreeNode* root, long long cursum, int target) {
        if(root == nullptr) return 0;  
        cursum += root->val;

        int ans = 0;
        ans += mp[cursum-target];
        mp[cursum]++;
        ans += dfs(root->left, cursum, target);
        ans += dfs(root->right, cursum, target);
        mp[cursum]--;
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0]++;
        return dfs(root,0,targetSum);
    }
};