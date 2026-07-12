class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st(arr.begin(),arr.end());
        int rank = 1;
        unordered_map<int,int> mp;
        for(auto& it: st) {
            mp[it] = rank;
            rank++;
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};