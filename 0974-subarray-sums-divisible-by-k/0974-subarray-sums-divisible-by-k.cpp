class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans += mp[(sum%k + k)%k];
            mp[(sum%k + k)%k]++;
        }
        return ans;
    }
};