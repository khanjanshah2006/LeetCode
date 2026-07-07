class Solution {
public:
    vector<vector<double>> dp;
    vector<pair<int,int>> serve = {{100,0},{75,25},{50,50},{25,75}};
    double solve(double a, double b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        if(dp[a][b] != -1) return dp[a][b];
        double ans = 0.0;
        for(auto& s: serve) {
            ans += 0.25 * solve(a - s.first, b - s.second);
        }
        return dp[a][b] = ans;
    }

    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        dp.assign(n+1, vector<double> (n+1,-1));
        return solve(n,n);
    }
};