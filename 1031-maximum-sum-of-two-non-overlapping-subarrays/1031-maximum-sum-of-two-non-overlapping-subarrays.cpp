class Solution {
public:
	vector<int> bestPrefix(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> ans;
		int sum = 0;
		for(int i = 0; i < k; i++) sum += nums[i];
		ans.push_back(sum);
		for(int i = k; i < n; i++) {
			sum += nums[i] - nums[i-k];
			ans.push_back(sum);
		}
		for(int i = ans.size()-2; i >= 0; i--) {
			ans[i] = max(ans[i],ans[i+1]);
		}
		return ans;
	}
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    	int n = nums.size();
    	vector<int> len2 = bestPrefix(nums,secondLen);
    	int sum = 0;
    	int ans = 0;
    	for(int i=0; i < firstLen; i++) sum += nums[i];
    	ans = sum + len2[firstLen];
    	for(int i = firstLen; i < n-secondLen; i++) {
    		sum += nums[i]-nums[i-firstLen];
    		ans = max(ans, sum+len2[i+1]);
    	}
    	sum = 0;
    	vector<int> len1 = bestPrefix(nums,firstLen);
    	for(int i = 0; i < secondLen; i++) sum += nums[i];
    	ans = max(ans, sum + len1[secondLen]);
    	for(int i = secondLen; i < n-firstLen; i++) {
    		sum += nums[i]-nums[i-secondLen];
    		ans = max(ans, sum + len1[i+1]);
    	}
    	return ans;
    }
};