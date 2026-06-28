class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSub = nums[0];
        int curSum = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++) {
            curSum = max(nums[i], curSum + nums[i]);
            maxSub = max(maxSub, curSum);
        }
        if(maxSub < 0) return maxSub;
        int minSub = nums[0];
        curSum = nums[0];
        int total_sum = nums[0];
        for(int i=1; i<n; i++) {
            curSum = min(nums[i], curSum + nums[i]);
            minSub = min(minSub, curSum);
            total_sum += nums[i];
        }
        int cirSub = total_sum - minSub;
        return max(cirSub, maxSub);
        
    }
};