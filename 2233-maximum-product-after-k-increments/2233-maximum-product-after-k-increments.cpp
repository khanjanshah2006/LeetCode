class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++) pq.push(nums[i]);
        while(k--) {
            int u = pq.top();
            pq.pop();
            pq.push(u+1);
        }
        long long mod = 1e9+7;
        long long ans = 1;
        while(!pq.empty()) {
            ans = (ans * pq.top())%mod;
            pq.pop();
        }
        return ans%mod;
    }
};