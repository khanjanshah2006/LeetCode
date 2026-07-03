class Solution {
public:
    int n;
    long long mod = 1e9+7;
    vector<int> dp;
    int solve(int i, string& s, int& k) {
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        long long ans = 0;
        long long num = 0;
        for(int len = 1; len <= n-i; len++) {
            num = num * 10 + (s[i+len-1] - '0');
            if(1 <= num && num <= k) {
                int new_i = i+len;
                ans = (ans + solve(new_i,s,k)) % mod;
            } else {
                break;
            }
        } 
        return dp[i] = ans;
    }


    int numberOfArrays(string s, int k) {
        n = s.length();
        dp.assign(n+1,-1);
        return solve(0,s,k);
    }
};