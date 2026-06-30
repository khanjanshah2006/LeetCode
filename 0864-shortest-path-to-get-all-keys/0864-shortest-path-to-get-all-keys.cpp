class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total_keys = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '@') {
                    q.push({{i,j},0});
                } else if( grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    total_keys++;
                }
            }
        }
        int target = (1 << total_keys)-1;
        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n, vector<bool>(target+1,false)));
        visited[q.front().first.first][q.front().first.second][0] = true;
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front().first.first;
                int j = q.front().first.second;
                int keys = q.front().second;
                q.pop();
                if(keys == target) return level;
                for(auto& dir: directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] != '#') {
                        int new_keys = keys;
                        if(grid[ni][nj] >= 'A' && grid[ni][nj] <= 'F') {
                            bool possible = ((keys >> (grid[ni][nj]-'A')) & 1);
                            if(!possible) {
                                continue;
                            }
                        }
                        if(grid[ni][nj] >= 'a' && grid[ni][nj] <= 'f'){
                            new_keys = (1 << (grid[ni][nj] - 'a')) | keys;
                        }

                        if(!visited[ni][nj][new_keys]) {
                            visited[ni][nj][new_keys] = true;
                            q.push({{ni,nj},new_keys});
                        }
                    } 
                }
            }
            level++;
        }
        return -1;
    }
};