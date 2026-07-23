class Solution {
public:

    double dfs(string u, string target, unordered_map<string,vector<pair<string,double>>>&adj, unordered_set<string>& visited, double curr) {
        if(u == target) return curr;
        visited.insert(u);
        for(auto& edge: adj[u]) {
            string v = edge.first;
            double w = edge.second;
            if(visited.find(v) == visited.end()) {
                double ans = dfs(v,target,adj,visited,curr*w);
                if(ans == -1.0) continue;
                return ans;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        int n = values.size();
        for(int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        } 
        vector<double> result;
        for(auto& query: queries) {
            string u = query[0];
            string v = query[1];
            if(adj.find(u) == adj.end() || adj.find(v) == adj.end()) {
                result.push_back(-1.0);
                continue;
            } 
            unordered_set<string> visited;
            result.push_back(dfs(u,v,adj,visited,1.0));
        }
        return result;
    }
};