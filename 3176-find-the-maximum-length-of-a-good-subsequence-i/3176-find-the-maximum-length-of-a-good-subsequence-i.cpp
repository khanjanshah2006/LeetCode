class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        vector<int> maxLen(k+1,0);
        dp[0][0] = 1;
        maxLen[0] = 1;
        mp[nums[0]] = 0;
        for(int i=1; i < n; i++) {
        	for(int j = 0; j <= k; j++) {
        		int case1 = 1;
        		if(mp.find(nums[i]) != mp.end()) {
        			case1 = 1 + dp[mp[nums[i]]][j];
        		}
       			int case2 = (j >= 1) ? 1 + maxLen[j-1] : 0;
       			dp[i][j] = max(case1, case2);
        	}
        	for (int j = 0; j <= k; j++) {
                maxLen[j] = max(maxLen[j], dp[i][j]);
            }
        	mp[nums[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i <= k; i++) {
        	ans = max(ans,maxLen[i]);
        }
        return ans;
    }
};