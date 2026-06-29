class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        long long sum = 0;
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL) % p;
        mp[(total_sum + 0)%p] = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mp[(total_sum + sum)%p] = i;
            if(mp.find(sum%p) != mp.end()) {
                ans = min(ans, i - mp[sum%p]);
            }
        }
        return (ans < n) ? ans : -1;
    }
};