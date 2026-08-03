class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    	int n = nums.size();
    	long long sum = accumulate(nums.begin(), nums.end(),0LL);
    	if(sum < x) return -1;
    	long long target = sum - x;
    	if(target == 0) return n;
    	int i = 0;
    	long long curSum = 0;
    	int ans = -1;
    	for(int j = 0; j < n; j++) {
    		curSum += nums[j];
    		while(curSum > target && i <= j) {
    			curSum -= nums[i];
    			i++;
    		}
    		if(curSum == target) {
    			ans = max(ans,j-i+1);
    		}
    	}
    	if(ans == -1) return -1;
    	return n-ans;
    }
};