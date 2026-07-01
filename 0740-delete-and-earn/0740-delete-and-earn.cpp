class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto& num: nums) {
            mp[num]++;
        }
        vector<int> arr;
        for(auto& it: mp) arr.push_back(it.first);
        int n = mp.size();
        vector<long long> dp(n,0);
        dp[0] = (long long)arr[0] * mp[arr[0]];
        for(int i=1; i<n; i++) {
            long long skip = dp[i-1];
            long long take = (long long)arr[i] * mp[arr[i]];
            int j=i-1;
            while(j >= 0 && arr[i]-arr[j] <= 1) j--;
            if(j >= 0) take+= dp[j];
            dp[i] = max(skip,take);
        }
        return dp[n-1];
    }
};