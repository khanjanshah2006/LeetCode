class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) {
                nums[i] = n+2; // max possible answer is n+1
            }
        }
        for(int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if(val <= n) {
                if(nums[val-1] > 0) {
                    nums[val-1] = -nums[val-1];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};