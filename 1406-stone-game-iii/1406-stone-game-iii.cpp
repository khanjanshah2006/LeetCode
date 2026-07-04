class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& stoneValue) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int result = stoneValue[i] - solve(i+1,stoneValue);
        if(i + 1 < n) {
            result = max(result, stoneValue[i] + stoneValue[i+1] - solve(i+2,stoneValue));
        }
        if(i + 2 < n) {
            result = max(result, stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(i+3,stoneValue));
        }
        return dp[i] = result;

    }


    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n+1,-1);
        int diff = solve(0,stoneValue);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        return "Tie";
    }
};