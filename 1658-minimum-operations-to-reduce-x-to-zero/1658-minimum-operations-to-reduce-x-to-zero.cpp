class Solution {
public:
    int maximumSizeSubarray(vector<int>& nums, long long k) {
    	int n = nums.size();
    	unordered_map<long long,int> mp;
    	mp[0] = -1;
    	long long sum = 0;
    	int size = -1;
    	for(int i=0; i < n; i++) {
    		sum += nums[i];
    		long long needed = sum-k;
    		if(mp.find(needed) != mp.end()) {
    			size = max(size,i-mp[needed]);
    		}
    		if(mp.find(sum) == mp.end()) {
    			mp[sum] = i;
    		}
    	}
    	return size;
    }
    int minOperations(vector<int>& nums, int x) {
    	long long sum = accumulate(nums.begin(),nums.end(),0LL);
    	if(sum < x) return -1;
    	if(sum-x == 0) return nums.size();
    	int maxSubarr = maximumSizeSubarray(nums, sum-x);
    	if(maxSubarr == -1) return -1;
    	return nums.size() - maximumSizeSubarray(nums,sum-x);   
    }
};