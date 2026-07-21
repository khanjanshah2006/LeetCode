class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int> mp;
        int n = x.size();
        for(int i = 0; i < n; i++) {
            mp[x[i]] = max(mp[x[i]], y[i]);
        }
        vector<int> ans;
        for(auto& it: mp) {
            ans.push_back(it.second);
        }
        int sz = ans.size();
        if(sz < 3) return -1;
        sort(ans.begin(),ans.end());
        return ans[sz-1] + ans[sz-2] + ans[sz-3];
    }
};