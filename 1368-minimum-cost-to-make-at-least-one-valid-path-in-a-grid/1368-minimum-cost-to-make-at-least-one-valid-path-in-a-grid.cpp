class Solution {
public:
    typedef pair<int,int> P;
    typedef pair<int,pair<int,int>> PP;
    vector<P> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dist(m*n + 1, 1e9);
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0,{0,0}});
        dist[0] = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            int ux = pq.top().second.first;
            int uy = pq.top().second.second;
            pq.pop();
            if(d > dist[ux*n + uy]) continue;
            for(int i=0; i<4; i++) {
                int vx = ux + dir[i].first;
                int vy = uy + dir[i].second;
                if(vx >= 0 && vy >= 0 && vx < m && vy < n) {
                    int cost = (grid[ux][uy]-1 == i) ? 0 : 1;
                    if(d+cost < dist[vx*n + vy]) {
                        dist[vx*n + vy] = d + cost;
                        pq.push({d+cost,{vx,vy}});
                    }
                }
            }
        }
        return dist[m*n - 1];
    }
};