class Solution {
public:
    vector<int> size;
    vector<int> parent;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x == y) return false; // already connected , no need to connect
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        size.assign(n,1);
        parent.resize(n);
        int comp = n;
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j  < n; j++) {
                if(isConnected[i][j] == 1) {
                    if(Union(i,j)) comp--;
                }
            }
        }    
        return comp;
    }
};