class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
       	int i = 0;
       	int j = costs.size()-1;
       	priority_queue<int,vector<int>,greater<int>> start,end;
       	while(k--) {
       		while(start.size() < candidates && i <= j) {
       			start.push(costs[i]);
       			i++;
       		}
       		while(end.size() < candidates && i <= j) {
       			end.push(costs[j]);
       			j--;
       		}
       		int a = start.empty() ? INT_MAX : start.top();
       		int b = end.empty() ? INT_MAX :end.top();
       		if(a <= b) {
       			ans += a;
       			start.pop();
       		}else {
       			ans += b;
       			end.pop();
       		}
       	}
       	return ans;
    }
};