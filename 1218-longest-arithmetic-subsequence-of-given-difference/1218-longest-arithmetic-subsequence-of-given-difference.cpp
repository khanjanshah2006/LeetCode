class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int element = arr[i] - difference;
            if(mp.find(element) == mp.end()) {
                mp[arr[i]] = 1;
            } else {
                mp[arr[i]] = mp[element] + 1;
            }
            ans = max(ans,mp[arr[i]]);
        }
        return ans;
    }
};