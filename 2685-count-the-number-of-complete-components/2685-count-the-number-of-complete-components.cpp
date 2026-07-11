class Solution {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& adj,int &totaledge, int& totalnode) {
        visited[i] = true;
        totalnode++;
        totaledge += adj[i].size();
        for(auto& node: adj[i]) {
            if(!visited[node]) {
                dfs(node,visited,adj,totaledge,totalnode);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int totalnode = 0;
            int totaledge = 0;
            if(!visited[i]) {
                dfs(i,visited,adj,totaledge,totalnode);
                totaledge = totaledge/2;
                if(totaledge == totalnode*(totalnode-1)/2 ) ans++;
            }
        }
        return ans;
    }
};