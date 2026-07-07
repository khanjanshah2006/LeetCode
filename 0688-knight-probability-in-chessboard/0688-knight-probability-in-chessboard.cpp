class Solution {
public:
    int N;
    vector<pair<int,int>> directions = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
    vector<vector<vector<double>>> dp;
    double solve(int k,int i, int j) {
        if(k == 0) return 1;
        if(dp[k][i][j] != -1) return dp[k][i][j];
        double ans = 0;
        for(auto& dir: directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if(ni >= 0 && nj >= 0 && ni < N && nj < N) {
                ans += solve(k-1,ni,nj)/8.0;
            }
        }
        return dp[k][i][j] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        N = n;
        dp.assign(k+1,vector<vector<double>>(n,vector<double>(n,-1)));
        return solve(k,row,column);
    }
};