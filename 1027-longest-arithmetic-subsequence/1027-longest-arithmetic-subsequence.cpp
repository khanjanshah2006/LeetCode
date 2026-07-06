class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        vector<vector<int>> dp(n,vector<int>(1001,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = dp[j][d] > 0 ? (dp[j][d] + 1) : 2;
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};