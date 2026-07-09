class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    bool solve(int i, int j, string s, string p) {
        if(j == m) {
            if(i == n) return true;
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        bool flag = false;
        if(i < n && (s[i] == p[j] || p[j] == '.')) flag = true;
        if(j+1 < m && p[j+1] == '*') {
            bool nottake = solve(i,j+2,s,p);
            bool take = flag && solve(i+1,j,s,p);
            ans = take || nottake;
        } else {
            ans = flag && solve(i+1,j+1,s,p);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        dp.assign(n+1,vector<int> (m+1,-1));
        return solve(0,0,s,p);
    }
};