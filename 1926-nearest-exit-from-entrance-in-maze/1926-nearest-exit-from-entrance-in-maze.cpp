class Solution {
public:
    int m,n;
    int sx,sy;
    bool isValid(int i, int j) {
        if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (i != sx || j != sy)) return true;
        return false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        sx = entrance[0];
        sy = entrance[1];
        if(maze[sx][sy] == '+') return -1;
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        m = maze.size();
        n = maze[0].size();
        queue<pair<int,int>> q;
        int level = 0;
        q.push({sx,sy});
        maze[sx][sy] = '+';
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(isValid(i,j)) return level;
                for(auto& dir: directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && maze[ni][nj] == '.') {
                        maze[ni][nj] = '+';
                        q.push({ni,nj});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};