class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<pair<int,int>,int> P;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<P> q;
        bool visited[m][n][k+1];
        memset(visited, false , sizeof(visited));
        visited[0][0][0] = true;
        q.push({{0,0},0});
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int i = q.front().first.first;
                int j = q.front().first.second;
                int cur_k = q.front().second;
                q.pop();
                if(i == m-1 && j == n-1) return level;
                for(auto& dir: directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(ni >= 0  && nj >= 0 && ni < m && nj < n) {
                        if(grid[ni][nj] == 1 && cur_k+1 <= k && !visited[ni][nj][cur_k+1]){
                            q.push({{ni,nj}, cur_k +1});
                            visited[ni][nj][cur_k+1] = true;
                        }
                        else if(grid[ni][nj] == 0 && !visited[ni][nj][cur_k]){
                            q.push({{ni,nj},cur_k});
                            visited[ni][nj][cur_k] = true;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};