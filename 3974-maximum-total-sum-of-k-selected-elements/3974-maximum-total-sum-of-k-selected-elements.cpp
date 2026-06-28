class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long maxSum = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n-1;
        while(i >= 0 && k--) {
            if(mul >= 1) {
                maxSum += (long long)nums[i] * mul;
            }else {
                maxSum += (long long)nums[i];
            }
            mul--;
            i--;
        }
        return maxSum;
    }
};