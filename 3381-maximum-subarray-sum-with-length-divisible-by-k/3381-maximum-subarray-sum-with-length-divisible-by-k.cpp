class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<long long> prefix(n+1,0);
        prefix[0] = 0;
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        unordered_map<int,int> mp;
        long long sum = LLONG_MIN;
        mp[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(mp.find(i % k) != mp.end()) {
                int j = mp[i % k];
                sum = max<long long>(sum, prefix[i] - prefix[j]);
                if(prefix[j] > prefix[i]) {
                    mp[i % k] = i;
                }
            } else {
                mp[i % k] = i;
            }
        }
        return sum;

    }
};