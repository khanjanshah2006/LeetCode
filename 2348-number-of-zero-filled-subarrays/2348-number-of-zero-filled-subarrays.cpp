class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long group = 0;
        int i = 0;
        int n = nums.size();
        long long ans = 0;
        while (i < n) {
            if (nums[i] == 0) {
                group++;
                i++;
            } else {
                ans += group * (group + 1) * 1LL / 2;
                group = 0;
                while (i < n && nums[i] != 0)
                    i++;
            }
        }
        ans += group * (group + 1) * 1LL / 2;
        return ans;
    }
};