class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n;
    int solve(int person, int m ,int i, vector<int>& piles) {
        if(i >= n) return 0;
        if(dp[person][m][i] != -1) return dp[person][m][i];
        int ans = (person == 1) ? -1 : INT_MAX;
        int sum = 0; 
        for(int x = 1; x <= min(2*m,n-i); x++) {
            sum += piles[i+x-1];
            if(person == 1) {
                ans = max(ans, sum + solve(0,max(m,x),i+x,piles));
            }else {
                ans = min(ans, solve(1,max(m,x),i+x,piles));
            }
        }
        return dp[person][m][i] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(2,vector<vector<int>>(n+1, vector<int>(n+1,-1)));
        return solve(1,1,0,piles);
    }
};