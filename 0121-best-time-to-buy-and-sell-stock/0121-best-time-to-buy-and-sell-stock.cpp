class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int low = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            ans = max(ans,prices[i]-low);
            low = min(low,prices[i]);
        }
        return (ans < 0) ? 0 : ans;
    }
};