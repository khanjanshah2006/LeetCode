class Solution {
public:
    int ans = 0;
    int totalpossible;
    int m,n;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(int i, int j , int count, vector<vector<int>>& grid) {
        if(grid[i][j] == 2) {
            if(count == totalpossible) ans++;
            return;
        }     
        grid[i][j] = -1;   
        for(auto& dir: directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] != -1) {
                solve(ni,nj, count+1, grid);
            }
        }
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        totalpossible = 0;
        int x,y;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) totalpossible++;
                else if(grid[i][j] == 1) {
                    totalpossible++;
                    x = i;
                    y = j; 
                }
            }
        }
        solve(x,y,0,grid);
        return ans;
    }
};