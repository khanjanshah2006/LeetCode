class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    long long mod = 1e9+7;
    vector<vector<int>> dp;
    long long solve(int i , int j, vector<vector<int>>& grid) {
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(auto& dir: directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                if(grid[ni][nj] > grid[i][j]) {
                    ans = (ans + solve(ni,nj,grid)) % mod;
                }
            }
        }
        return dp[i][j] = ans % mod;
    }
 
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m+1, vector<int>(n+1,-1));
        long long ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = (ans + solve(i,j,grid)) % mod;
            }
        }
        return ans % mod;
    }
};