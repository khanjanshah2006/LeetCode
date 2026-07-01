class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int> mp;
        for(auto& num: power) {
            mp[num]++;
        }
        vector<int> arr;
        for(auto& it: mp) {
            arr.push_back(it.first);
        }
        int n = mp.size();
        vector<ll> dp(n);
        dp[0] = (ll)arr[0]*mp[arr[0]];
        for(int i=1; i<n; i++) {
            ll skip = dp[i-1];
            ll take = (ll)arr[i]*mp[arr[i]];
            int j=i-1;
            while(j >= 0 && arr[i]-arr[j] <= 2) j--;
            if(j >= 0) take += dp[j];

            dp[i] = max(skip,take);
        }
        return dp[n-1];
    }
};