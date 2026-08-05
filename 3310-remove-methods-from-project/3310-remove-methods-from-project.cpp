class Solution {
public:
	void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited,queue<int>& q) {
		visited[u] = true;
		q.push(u);
		for(auto& v: adj[u]) {
			if(!visited[v]) {
				dfs(v,adj,visited,q);
			}
		}
	}

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        vector<vector<int>> adjR(n);
        for(auto& edge: invocations) {
        	int u = edge[0];
        	int v = edge[1];
        	adj[u].push_back(v);
        	adjR[v].push_back(u);
        }
        queue<int> q;
        vector<int> arr(n);
        for(int i=0; i < n; i++) arr[i] = i;
        dfs(k,adj,visited,q);
        while(!q.empty()) {
        	int u = q.front();
        	q.pop();
        	for(auto& v: adjR[u]) {
        		if(!visited[v]) {
                    vector<int> arr(n);
                    for(int i=0; i < n; i++) arr[i] = i;
                    return arr;
        		}
        	}
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
        	if(visited[i] == false) {
        		ans.push_back(i);
        	}
        }
        return ans;
    }
};