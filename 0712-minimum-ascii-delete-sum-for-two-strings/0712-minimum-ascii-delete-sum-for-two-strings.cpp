class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = s1[i] + dp[i+1][j+1];
                }else {
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        int commonSum = dp[0][0];
        int sum1 = 0;
        int sum2 = 0;
        for(auto&c: s1) sum1 += c;
        for(auto&c: s2) sum2 += c;
        return sum1 + sum2 - (2*commonSum);
    }
};