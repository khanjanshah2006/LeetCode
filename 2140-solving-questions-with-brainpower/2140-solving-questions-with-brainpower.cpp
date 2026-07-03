class Solution {
public:
    int n;
    vector<long long> dp;
    long long solve(int i,vector<vector<int>>& questions) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long take = questions[i][0] + solve(i + questions[i][1]+1, questions);
        long long notTake = solve(i+1, questions);
        return dp[i] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.assign(n+1, -1);
        return solve(0,questions);
    }
};