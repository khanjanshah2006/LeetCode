class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<vector<int>>& piles, int toTake) {
        if (toTake == 0)
            return 0;
        if (i == piles.size())
            return INT_MIN;
        if (dp[i][toTake] != -1)
            return dp[i][toTake];
        int n = piles[i].size();
        int ans = solve(i + 1, piles, toTake);
        for (int j = 0; j < n; j++) {
            if (j + 1 > toTake)
                break;
            int take = solve(i + 1, piles, toTake - (j + 1));
            if (take == INT_MIN)
                continue;
            ans = max(ans, piles[i][j] + take);
        }
        return dp[i][toTake] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        for (auto& pile : piles) {
            if (pile.size() == 0)
                continue;
            int sum = pile[0];
            int n = pile.size();
            for (int i = 1; i < n; i++) {
                sum += pile[i];
                pile[i] = sum;
            }
        }
        return solve(0, piles, k);
    }
};