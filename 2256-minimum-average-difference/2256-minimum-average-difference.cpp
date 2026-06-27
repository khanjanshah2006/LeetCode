class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int idx = 0;
        int minDiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int left = prefix[i]/(i+1);
            int right = (i != n-1) ? (prefix[n-1]-prefix[i])/(n-i-1) : 0;
            int diff = abs(left-right);
            if(diff < minDiff) {
                minDiff = diff;
                idx = i;
            }
        }
        return idx;
    }
};