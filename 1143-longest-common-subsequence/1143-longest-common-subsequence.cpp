class Solution {
public:
    vector<vector<int>> dp;
    int n1,n2;
    int solve(int i, int j, string& text1, string& text2) {
        if(i == n1 || j == n2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i+1,j+1,text1,text2);
        }
        int ans = max(solve(i+1,j,text1,text2), solve(i,j+1,text1,text2));
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.length();
        n2 = text2.length();
        dp.assign(n1,vector<int>(n2,-1));
        return solve(0,0,text1,text2);
    }
};