class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int min_len = INT_MAX;
        int curSum = 0;
        while(j < n) {
            curSum += nums[j];
            while(i <= j && curSum >= target) {
                min_len = min(min_len, j-i+1);
                curSum -= nums[i];
                i++;
            }
            j++;
        }
        if(min_len == INT_MAX) return 0;
        return min_len;
    }
};