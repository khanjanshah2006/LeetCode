class Solution {
public:
    typedef pair<long long,pair<int,int>> P;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>> dist(n,vector<long long>(power+1, LLONG_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[source][power] = 0;
        pq.push({0,{source,power}});
        while(!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second.first;
            int remPow = pq.top().second.second;
            pq.pop();
            if(d > dist[u][remPow]) continue;
            if(remPow < cost[u]) continue;
            for(auto& edge: adj[u]) {
                int v = edge.first;
                int t = edge.second;
                if(d+t < dist[v][remPow-cost[u]]){
                    dist[v][remPow-cost[u]] = d+t;
                    pq.push({d+t,{v,remPow-cost[u]}});
                }
            }
        }
        long long minTime = LLONG_MAX;
        long long maxRemPow = -1;
        for(int i=0; i <= power; i++) {
            if(dist[target][i] <= minTime) {
                minTime = dist[target][i];
            }
        }
        for(int i=power; i>=0; i--) {
            if(dist[target][i] == minTime) {
                maxRemPow = i;
                break;
            }
        }
        if(minTime == LLONG_MAX) return {-1,-1};
        return {minTime,maxRemPow};
    }
};