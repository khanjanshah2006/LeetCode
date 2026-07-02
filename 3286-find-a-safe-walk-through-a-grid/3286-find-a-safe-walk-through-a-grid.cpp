class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n,1e9));
        deque<pair<int,int>> q;
        q.push_front({0,0});
        dist[0][0] = grid[0][0];
        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop_front();
            for(auto& dir: directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int w = grid[ni][nj];
                    if(dist[i][j] + w < dist[ni][nj]) {
                        dist[ni][nj] = dist[i][j] + w;
                        if(w) {
                            q.push_back({ni,nj});
                        }else {
                            q.push_front({ni,nj});
                        }
                    }
                }
            }
        }
        if(dist[m-1][n-1] < health) return true;
        return false;
    }
};