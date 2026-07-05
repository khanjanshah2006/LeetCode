class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3,0));
        for(int i = n-1; i >= 0; i--) {
            for(int state = 0; state < 3; state++) {
                int ans;
                if(state == 0) {
                    int case1 = prices[i] + dp[i+1][1];
                    int case2 = dp[i+1][0];
                    ans = max(case1,case2);
                }else if (state == 1) {
                    ans = dp[i+1][2];
                } else {
                    int case1 = -prices[i] + dp[i+1][0];
                    int case2 = dp[i+1][2];
                    ans = max(case1,case2);
                }
                dp[i][state] = ans;
            }
        }
        return dp[0][2];
    }
};