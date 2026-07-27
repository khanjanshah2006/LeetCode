class Solution {
public:
    int dp[10001][2][101];
    int n;
    int solve(int i, int hold, int k, vector<int>& arr) {
        if(i == n || k == 0) return 0;
        if(dp[i][hold][k] != -1) return dp[i][hold][k];
        int ans;
        if(hold == 0) {
            //free;
            int case1 = solve(i+1,hold,k,arr); //stay free;
            int case2 = -arr[i] + solve(i+1,!hold,k,arr); // buy stock
            ans = max(case1,case2);
        }else{
            //hold
            int case1 = solve(i+1,hold,k,arr); // stay hold
            int case2 = arr[i] + solve(i+1,!hold,k-1,arr); // sell
            ans = max(case1,case2);
        }
        return dp[i][hold][k] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,k,prices);
    }
};