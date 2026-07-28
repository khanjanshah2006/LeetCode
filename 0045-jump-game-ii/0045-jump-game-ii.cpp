class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxend = 0;
        int currend = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            maxend = max(maxend, i+nums[i]);
            if(i == currend) {
                ans++;
                currend = maxend;
            }
        }
        return ans;
    }
};