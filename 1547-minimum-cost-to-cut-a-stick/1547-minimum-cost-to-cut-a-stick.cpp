class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int N = cuts.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int l = 2; l < N; l++) {
            for (int i = 0; i + l < N; i++) {
                int j = i + l;
                int result = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    result =
                        min(result, (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = result;
            }
        }
        return dp[0][N - 1];
    }
};