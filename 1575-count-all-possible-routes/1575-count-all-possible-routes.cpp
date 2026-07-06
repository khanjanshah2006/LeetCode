class Solution {
public:
    long long mod = 1e9+7;
    int f,n;
    vector<vector<int>> dp;
    int solve(int i, int left, vector<int>& locations) {
        if(left < 0) {
            return 0;
        }
        if(dp[i][left] != -1) return dp[i][left];
        int ans = 0;
        if(i == f) ans++;
        for(int k = 0; k < n; k++) {
            if(i == k) continue;
            int dist = abs(locations[i] - locations[k]);
            ans = (ans + solve(k,left-dist, locations)) % mod;
        }
        return dp[i][left] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        f = finish;
        n = locations.size();
        dp.assign(n,vector<int> (fuel+1,-1));
        return solve(start,fuel,locations);
    }
};