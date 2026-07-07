class Solution {
public:
    long long mod = 1e9+7;
    vector<vector<long long>> dp;
    long long solve(int i, int d, int& n, int& goal, int& k) { // d= cnt of unique elements till index i
        if(i == goal) {
            if(d == n) return 1;
            return 0;
        }
        if(dp[i][d] != -1) return dp[i][d];
        long long ans = 0;
        if(n > d) ans = (ans + (long long)(n-d)*solve(i+1,d+1,n,goal,k))%mod;
        if(d > k) ans = (ans + (long long)(d-k)*solve(i+1,d,n,goal,k))%mod;
        return dp[i][d] = ans%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        dp.assign(goal,vector<long long>(n+1,-1));
        return solve(0,0,n,goal,k);
    }
};