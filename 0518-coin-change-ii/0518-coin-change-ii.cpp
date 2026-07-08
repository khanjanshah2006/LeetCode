class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int amount, vector<int>& coins) {
        if(i == n || amount < 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(amount == 0) return dp[i][amount] = 1;
        int skip = solve(i+1,amount, coins);
        int take = solve(i,amount-coins[i],coins);
        return dp[i][amount] = take + skip;
    }


    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};