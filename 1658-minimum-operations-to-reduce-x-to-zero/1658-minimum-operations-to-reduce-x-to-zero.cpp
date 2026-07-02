class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        int target = sum - x;
        if(target < 0) return -1;
        sum = 0;
        unordered_map<int,int> mp;
        int ans = INT_MIN;
        mp[0] = -1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            mp[sum] = i;
            if(mp.find(sum - target) != mp.end()) {
                ans = max(ans , i - mp[sum-target]);
            }
        }
        return (ans == INT_MIN) ? -1: n- ans;
    }
};