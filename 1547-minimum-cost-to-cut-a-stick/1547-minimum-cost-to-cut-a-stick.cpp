class Solution {
public:
    int N;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& cuts) {
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int result = INT_MAX;
        for(int k = i+1; k < j; k++) {
            result = min(result, (cuts[j]-cuts[i]) + solve(i,k,cuts) + solve(k,j,cuts));
        }
        return dp[i][j] = result;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        N = cuts.size();
        dp.assign(N,vector<int>(N,-1));
        return solve(0,N-1,cuts);
    }
};