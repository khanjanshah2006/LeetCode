class Solution {
public:
    vector<vector<int>> dp;
    int n,K;
    int solve(int i, int k, vector<int>& nums) {
        if(dp[i][k] != -1) return dp[i][k];
        int maxLen = 1;
        for(int j = i+1; j < n; j++) {
            if(nums[i] == nums[j]) {
                maxLen = max(maxLen, 1 + solve(j,k,nums));
            }else if(k+1 <= K) {
                maxLen = max(maxLen, 1 + solve(j,k+1,nums));
            }
        }
        return dp[i][k] = maxLen;
    }

    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
        dp.assign(n+1,vector<int> (k+1,-1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(i,0,nums));
        }
        return ans;
    }
};