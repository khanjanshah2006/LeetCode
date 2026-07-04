class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int opr, vector<int>& nums, int mask) {
        int ans = 0;
        if(dp[mask] != -1) return dp[mask];
        for(int i = 0; i <= n-2; i++) {
            if(mask & (1 << i)) continue;
            for(int j = i+1; j < n; j++) {
                if(mask & (1 << j)) continue;
                int newMask = (mask | (1 << i) | (1 << j));
                int score = opr*gcd(nums[i],nums[j]) + solve(opr+1,nums,newMask);
                ans = max(ans,score);
            }
        }
        return dp[mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        dp.assign(1 << n, -1);
        return solve(1,nums,0);
    }
};