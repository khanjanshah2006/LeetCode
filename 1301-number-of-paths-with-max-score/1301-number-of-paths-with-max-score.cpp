class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        long long mod = 1e9+7;
        vector<pair<int,int>> directions = {{0,1},{1,0},{1,1}};
        vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(n,{INT_MIN,0})); //{m,p} max possible, number of path
        dp[m-1][n-1] = {0,1};
        board[0][0] = '0';
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(board[i][j] == 'X' || board[i][j] == 'S') continue;
                for(auto& dir: directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && board[ni][nj] != 'X') {
                        if(dp[ni][nj].first == INT_MIN) continue;
                        if(dp[i][j].first < dp[ni][nj].first  + (board[i][j] - '0')) {
                            dp[i][j].first = dp[ni][nj].first + (board[i][j] - '0');
                            dp[i][j].second = dp[ni][nj].second;
                        }else if(dp[i][j].first == dp[ni][nj].first + (board[i][j] - '0')) {
                            dp[i][j].second = (dp[i][j].second + dp[ni][nj].second) % mod;
                        }
                    }
                }
            }
        }
        if(dp[0][0].first == INT_MIN) return {0,0};
        return {dp[0][0].first, dp[0][0].second};
    }
};