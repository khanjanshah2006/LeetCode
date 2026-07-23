class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});       
                }
            }
        }
        int ans = 0;
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int ux = q.front().first;
                int uy = q.front().second;
                q.pop();
                for(auto& dir: directions) {
                    int nx = ux + dir.first;
                    int ny = uy + dir.second;
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return (ans == 0) ? 0 : ans-1;
    }
};