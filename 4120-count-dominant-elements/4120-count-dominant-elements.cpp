class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int ans = 0;
        ans += (nums[0] >= nums[1]);
        ans += nums[n-1] >= nums[n-2];
        for(int i = 1; i < n-1; i++) {
            float avg =  ( nums[i-1] + nums[i+1] )/ 2.0;
            ans += nums[i] >= avg;
        }
        return ans;
    }
};