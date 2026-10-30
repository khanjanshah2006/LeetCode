class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(int i, int add, vector<int>& nums) {
        if(i >= n) return 0;
        if(dp[i][add] != -1) return dp[i][add];
        long long skip = solve(i+1,add,nums);
        long long toadd = nums[i];
        if(add == 0) toadd = -toadd;
        long long take = solve(i+1,!add,nums)+toadd;
        return dp[i][add] = max(take,skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,vector<long long>(2,-1));
        return solve(0,1,nums);
    }
};