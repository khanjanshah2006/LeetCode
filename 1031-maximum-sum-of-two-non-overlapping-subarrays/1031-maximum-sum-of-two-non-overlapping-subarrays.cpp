class Solution {
public:
	int maxSubarray(vector<int>&nums, int start, int end, int len) {
		if(end-start+1 < len) return -1;
		int sum = 0;
		for(int i = 0; i < len; i++) {
			sum += nums[i+start];
		}
		int ans = sum;
		for(int i = start+len; i <= end; i++) {
			sum += nums[i] - nums[i-len];
			ans = max(ans,sum);
		}
		return ans;
	}

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i < firstLen; i++) sum += nums[i];
        int ans = sum + maxSubarray(nums,firstLen,n-1,secondLen);
    	for(int i = firstLen; i < n; i++) {
    		sum += nums[i] - nums[i-firstLen];
    		int left = maxSubarray(nums,0,i-firstLen,secondLen);
    		int right = maxSubarray(nums,i+1,n-1,secondLen);
    		int sum2 = max(left,right);
    		ans = max(ans, sum+sum2);
    	}
    	return ans;
    }
};