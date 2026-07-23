class Solution {
public:
    void dfs(int u, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[u] = true;
        for(int v: rooms[u]) {
            if(!visited[v]) {
                dfs(v,rooms,visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(0,rooms, visited);
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) return false;
        }
        return true;
    }
};