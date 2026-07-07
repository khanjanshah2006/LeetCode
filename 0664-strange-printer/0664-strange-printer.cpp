class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string& s) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1 + solve(i+1,j,s);
        for(int k = i+1; k <= j; k++) {
            if(s[i] == s[k])
                ans = min(ans, solve(i,k-1,s) + solve(k+1,j,s));
        }
        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        string ans;
        int n = s.length();
        ans += s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] != s[i-1]) {
                ans += s[i];
            }
        }
        cout << ans;
        int N = ans.size();
        dp.assign(N,vector<int>(N,-1));
        return solve(0,N-1,ans);
    }
};