class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int z = 0;
        set<int> even;
        set<int> odd;
        for(auto& ch: s) {
            if(ch == '0') z++;
        }
        for(int i = 0; i <= n; i++) {
            if(i == z) continue;
            if(i % 2 == 0) even.insert(i);
            else odd.insert(i);
        }
        queue<int> q;
        vector<int> dist(n+1,-1);
        q.push(z);
        dist[z] = 0;
        while(!q.empty()) {
            int curZ = q.front();
            q.pop();
            if(curZ == 0) return dist[curZ]; 
            int Min = curZ + k - 2*min(curZ,k);
            int Max = curZ + k - 2*max(0,k + curZ - n);
            
            set<int>& st = (Min % 2 == 0) ? even : odd;
            auto it = st.lower_bound(Min);

            while(it != st.end() && *it <= Max) {
                int newZ = *it;
                if(dist[newZ] == -1) {
                    dist[newZ] = dist[curZ] + 1;
                    if(newZ == 0) return dist[newZ];
                    q.push(newZ);
                }
                it = st.erase(it);
            }
        }
        return -1;
    }
};