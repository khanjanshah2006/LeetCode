class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
       	vector<int> ans(n,-1);
       	int len = 2*k + 1;
       	if(n < len) return ans;
       	long long sum = 0;
       	for(int i = 0; i < len; i++) {
       		sum += nums[i];
       	}
       	for(int i = k; i < n-k; i++) {
       		ans[i] = sum/len;
            if(i == n-k-1) break;
       		sum -= nums[i-k];
       		sum += nums[i+k+1];
       	}
       	return ans;
    }
};