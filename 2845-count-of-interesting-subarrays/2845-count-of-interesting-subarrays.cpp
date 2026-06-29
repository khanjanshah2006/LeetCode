class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) nums[i] = 1;
            else nums[i] = 0;
        }
        unordered_map<int,int> mp;
        mp[k % modulo]++;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans += mp[sum % modulo];
            mp[(sum + k) % modulo]++;
        }
        return ans;
    }
};