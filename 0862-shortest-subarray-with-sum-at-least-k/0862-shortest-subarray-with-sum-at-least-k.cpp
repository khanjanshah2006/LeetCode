class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n+1,0);
        for(int i = 0; i < n; i++) pre[i+1] = pre[i] + nums[i];
        deque<int> dq;
    	int ans = INT_MAX;
    	for(int j = 0; j <= n; j++) {
    		while(!dq.empty() && pre[j] - pre[dq.front()] >= k) {
    			ans = min(ans, j-dq.front());
    			dq.pop_front();
    		}
    		while(!dq.empty() && pre[dq.back()] >= pre[j]) {
    			dq.pop_back();
    		}
    		dq.push_back(j);
    	}

    	return (ans == INT_MAX) ? -1: ans;
    }
};