class Solution {
public:
    int n;
    vector<long long> dp;
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.assign(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int idx = min(n,i+questions[i][1]+1);
            long long take = questions[i][0] + dp[idx];
            long long notTake = dp[i+1];
            dp[i] = max(take,notTake);
        }
        return dp[0];
    }
};