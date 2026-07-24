class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int i = 0;
        int j = costs.size()-1;
        priority_queue<int, vector<int>, greater<int>> pq1,pq2;
        while(k--) {
            while(pq1.size() < candidates && i <= j) {
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size() < candidates && i <= j) {
                pq2.push(costs[j]);
                j--;
            }
            int a = pq1.empty() ? INT_MAX : pq1.top();
            int b = pq2.empty() ? INT_MAX : pq2.top();
            if(a <= b) {
                ans += pq1.top();
                pq1.pop();
            }else {
                ans += pq2.top();
                pq2.pop();
            }
        }
        return ans;
    }
};