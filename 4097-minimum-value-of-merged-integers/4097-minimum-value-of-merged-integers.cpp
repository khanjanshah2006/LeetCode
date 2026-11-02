class Solution {
public:

    int digit(int num) {
        int n = 0;
        while(num > 0) {
            n++;
            num /= 10;
        }
        return n;
    }

    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i+=2) {
            int number = nums[i]*pow(10,digit(nums[i+1]))  + nums[i+1];
            ans = min(ans,number);
        }
        return ans;
    }

};