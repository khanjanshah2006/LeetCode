class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> mp;
        for(int plank: planks) {
            mp[plank]++;
        }
        unordered_map<int,int> mp2;
        vector<int> arr;
        for(auto& it: mp) {
            mp2[it.first] = it.second;
            arr.push_back(it.first);
        }
        int n = mp.size();
        for(int i = 0; i < n; i++) {
            int a = arr[i];
            if(mp[a] >= 2) {
                mp2[2*a] += mp[a]/2;
            }
            for(int j = i+1; j < n; j++) {
                int b = arr[j];
                mp2[a+b] += min(mp[a],mp[b]);

            }
        }
        int ans = 0;
        for(auto& it: mp2) ans = max(ans,it.second);
        return ans;
    }
};