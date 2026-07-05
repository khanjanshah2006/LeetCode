class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int state, vector<int>& prices) {
        if(i == n) return 0;
        if(dp[i][state] != -1) return dp[i][state];
        int ans;
        if(state == 0) {
            int case1 = prices[i] + solve(i+1,1,prices);
            int case2 = solve(i+1,0,prices);
            ans = max(case1,case2);
        }else if (state == 1) {
            ans = solve(i+1,2,prices);
        }else {
            int case1 = -prices[i] + solve(i+1,0,prices);
            int case2 = solve(i+1,2,prices);
            ans = max(case1, case2);
        }
        return dp[i][state] = ans;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n+1, vector<int>(3,-1));
        return solve(0,2, prices);
    }
};