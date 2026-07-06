class Solution {
public:
    int n;
    vector<unordered_map<int,int>> dp; 
    int solve(int i, int diff, vector<int>& rods) {
        if(i == n) {
            if(diff == 0) {
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i].find(diff) != dp[i].end()) return dp[i][diff];
        int ans = 0;
        int case1 = rods[i] + solve(i+1, diff+rods[i],rods);
        int case2 = rods[i] + solve(i+1, diff-rods[i],rods);
        int case3 = solve(i+1, diff, rods);
        ans = max({case1,case2,case3});

        return dp[i][diff] = ans;
    }

    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        dp.resize(n+1);
        return solve(0,0,rods)/2;
    }
};