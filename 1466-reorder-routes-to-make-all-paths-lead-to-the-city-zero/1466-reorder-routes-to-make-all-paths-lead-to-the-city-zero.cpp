class Solution {
public:
    int ans = 0;
    vector<bool> visited;
    void dfs(int u,vector<vector<int>>& adj, set<pair<int,int>>& st) {
        visited[u] = true;
        for(auto&v : adj[u]) {
            if(!visited[v]) {
                if(st.find({u,v}) != st.end()) ans++;
                dfs(v,adj,st);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int,int>> st;
        for(auto& edges: connections) {
            int u = edges[0];
            int v = edges[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            st.insert({u,v});
        }
        visited.assign(n,false);
        dfs(0,adj,st);
        return ans;
    }
};