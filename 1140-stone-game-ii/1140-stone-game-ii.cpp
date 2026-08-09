class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int m, vector<int>& piles) {
        if(i >= n) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int ans = INT_MIN;
        int sum = 0;
        for(int x = 1; x <= min(2*m, n-i); x++) {
            sum += piles[i+x-1];
            ans = max(ans, sum - solve(i+x,max(m,x),piles));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        long long total = accumulate(piles.begin(),piles.end(),0);
        n = piles.size();
        dp.assign(n+1, vector<int>(n+1,-1));
        return (total+solve(0,1,piles))/ 2;
    }
};