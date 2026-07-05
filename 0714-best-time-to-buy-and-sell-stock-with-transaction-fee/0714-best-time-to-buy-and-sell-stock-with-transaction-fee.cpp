class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2, 0));
        for(int i = n-1; i >= 0; i--) {
            for(int state = 0; state < 2; state++) {
                int case1,case2;
                if(state == 0) {
                    case1 = prices[i] - fee + dp[i+1][1];
                    case2 = dp[i+1][0];
                }else {
                    case1 = -prices[i] + dp[i+1][0];
                    case2 = dp[i+1][1];
                }
                dp[i][state] = max(case1,case2);
            }
        }
        return dp[0][1];
    }
};