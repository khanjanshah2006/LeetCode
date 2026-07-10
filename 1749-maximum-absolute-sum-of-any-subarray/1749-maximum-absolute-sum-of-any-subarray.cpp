class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for(int i = 1; i < n; i++) {
            cur_sum = max(nums[i], nums[i] + cur_sum);
            max_sum = max(max_sum, cur_sum);
        }
        int min_sum = nums[0];
        cur_sum = nums[0];
        for(int i = 1; i < n; i++) {
            cur_sum = min(nums[i], nums[i] + cur_sum);
            min_sum = min(min_sum, cur_sum);
        }
        min_sum = min_sum * -1;
        return max(min_sum, max_sum);
    }
};