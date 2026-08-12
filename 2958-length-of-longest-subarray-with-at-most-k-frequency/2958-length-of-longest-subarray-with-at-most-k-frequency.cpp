class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        for(; j < n; j++) {
            mp[nums[j]]++;
            while(i < n && mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }   
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};