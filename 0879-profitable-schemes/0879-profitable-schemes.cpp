class Solution {
public:
    int N;
    long long mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    long long solve(int i, int remPeople, int curProfit,
                    vector<int>& group, vector<int>& profit, int& minProfit) {
        if (i == N || remPeople == 0) {
            return (curProfit >= minProfit) ? 1 : 0;
        }
        if (dp[i][remPeople][curProfit] != -1)
            return dp[i][remPeople][curProfit];
        long long take = 0;
        if (group[i] <= remPeople) {
            int newProfit = min(minProfit, curProfit + profit[i]);
            take = solve(i + 1, remPeople - group[i], newProfit, group, profit,
                         minProfit) %
                   mod;
        }
        long long notTake =
            solve(i + 1, remPeople, curProfit, group, profit, minProfit) % mod;
        return dp[i][remPeople][curProfit] = ((take + notTake) % mod);
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        N = group.size();
        dp.assign(N + 1,
                  vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return solve(0, n, 0, group, profit, minProfit);
    }
};