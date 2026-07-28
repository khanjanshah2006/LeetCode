class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& nums) {
        if(i >= n) return INT_MAX;
        if(i == n-1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j = 1; j <= nums[i]; j++) {
            int jump = solve(i+j,nums);
            if(jump != INT_MAX) {
                ans = min(ans,1+jump);
            }
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,-1);
        return solve(0,nums);
    }
};