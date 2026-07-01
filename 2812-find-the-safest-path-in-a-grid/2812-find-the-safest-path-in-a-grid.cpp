class Solution {
public:
    int n;
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    bool isvalid(const int& v,const vector<vector<int>>& dist) {
        if(dist[0][0] < v || dist[n-1][n-1] < v) return false;
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        queue<pair<int,int>> q;
        visited[0][0] = true;
        q.push({0,0});
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(i == n-1 && j == n-1) return true;
            for(auto& dir: directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if(ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] && dist[ni][nj] >= v) {
                    visited[ni][nj] = true;
                    q.push({ni,nj});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0 ;j<n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto& dir: directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if(ni >= 0 && nj >= 0 && ni < n && nj < n && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }
        int l = 0;
        int r = dist[0][0];
        int ans = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;
            if(isvalid(mid,dist)) {
                ans = mid;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        return ans;
    }
};