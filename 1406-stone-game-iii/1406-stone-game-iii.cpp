class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& arr) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int sum = 0;
        int ans = INT_MIN;
        for(int x = 1; x <= 3; x++) {
            if(i+x-1 == n) break;
            sum += arr[i+x-1];
            ans = max(ans, sum - solve(i+x,arr));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n+1,-1);
        int ans = solve(0,stoneValue);
        if(ans == 0) return "Tie";
        else if(ans > 0) return "Alice";
        return "Bob";
    }
};