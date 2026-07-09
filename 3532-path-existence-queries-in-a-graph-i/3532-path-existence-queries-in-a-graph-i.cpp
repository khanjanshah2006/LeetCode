class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        int curPar = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i]-nums[i-1] <= maxDiff) {
                parent[i] = curPar;
            } else {
                curPar = i;
            }
        }
        vector<bool> ans;
        for(auto& query: queries) {
            int u = query[0];
            int v = query[1];
            ans.push_back((parent[u] == parent[v]));
        }
        return ans;
    }
};