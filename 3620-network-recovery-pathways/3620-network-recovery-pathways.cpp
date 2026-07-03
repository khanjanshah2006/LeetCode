class Solution {
public:
    void topoSort(int i, vector<vector<pair<int, int>>>& adj,
                  vector<bool>& visited, vector<int>& topo) {
        visited[i] = true;
        for (auto& edge : adj[i]) {
            if (!visited[edge.first]) {
                topoSort(edge.first, adj, visited, topo);
            }
        }
        topo.push_back(i);
    }

    bool isValid(int mid, vector<vector<pair<int, int>>>& adj, long long k,
                 vector<int>& topo) {
        int n = adj.size();
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        for (int& u : topo) {
            if (dist[u] != 1e18) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    long long w = edge.second;
                    if (w >= mid) {
                        if (dist[u] + w < dist[v]) {
                            dist[v] = dist[u] + w;
                        }
                    }
                }
            }
        }
        if (dist[n - 1] <= k)
            return true;
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, c});
            }
        }
        vector<bool> visited(n, false);
        vector<int> topo;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topoSort(i, adj, visited, topo);
            }
        }
        reverse(topo.begin(), topo.end());
        int l = 0;
        int r = 1e9;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid, adj, k, topo)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};