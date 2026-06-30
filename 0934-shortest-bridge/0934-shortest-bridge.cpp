class Solution {
public:
    int n;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return;

        grid[i][j] = 2;
        q.push({i,j});
        for(auto& dir: directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            dfs(ni,nj, grid, q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        bool flag = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,grid,q);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto& dir: directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(ni >= 0 && nj >= 0 && ni < n && nj < n) {
                        if(grid[ni][nj] == 1) return level;
                        if(grid[ni][nj] == 0) {
                            grid[ni][nj] = 2;
                            q.push({ni,nj});
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};