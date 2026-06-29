class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += mp[nums[i] - i];
            mp[nums[i] - i]++;
        }
        long long total_pairs = (n * (n-1) * 1LL)/2*1LL;
        return total_pairs - ans;
    }
};