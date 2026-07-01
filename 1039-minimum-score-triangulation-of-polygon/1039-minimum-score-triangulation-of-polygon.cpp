class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& values, int i, int j) {
        if(j-i < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++) {
            int sum = solve(values,i,k) + (values[i]*values[k]*values[j]) + solve(values,k,j);
            ans = min(ans, sum);
        }
        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(values,0,n-1);
    }
};