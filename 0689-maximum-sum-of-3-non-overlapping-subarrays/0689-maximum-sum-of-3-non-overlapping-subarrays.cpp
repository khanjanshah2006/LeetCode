class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for(int i = 0; i < n; i++) {
        	prefix[i+1] = prefix[i] + nums[i];
        }
        vector<vector<long long>> dp(n+1,vector<long long>(4,0));
        for(int rem = 1; rem <= 3; rem++) {
        	for(int i = n-1; i >= 0; i--) {
        		long long skip = dp[i+1][rem];
        		long long take = LLONG_MIN;
        		if(i+k <= n) {
        			take = (prefix[i+k]-prefix[i]) + dp[i+k][rem-1];
        		}
        		dp[i][rem] = max(skip,take);
        	}
        }
        vector<int> ans;
        int i = 0;
        int rem = 3;
        while(rem > 0) {
        	long long skip = dp[i+1][rem];
        	long long take = LLONG_MIN;
        	if(i+k <= n){
        		take = (prefix[i+k]-prefix[i]) + dp[i+k][rem-1];
        	}
        	if(take >= skip) {
        		ans.push_back(i);
        		i += k;
        		rem--;
        	}else{
        		i++;
        	}
        }
        return ans;
    }
};