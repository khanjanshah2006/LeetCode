class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;
    int range(int s, int e) {
        return prefix[e+1]-prefix[s];
    }
    int solve(int start, int end) {
        if(start == end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MIN;
        for(int i = start; i < end; i++) {
            int left = range(start,i);
            int right = range(i+1,end);
            if(left > right) {
                int temp = right + solve(i+1,end);
                ans = max(ans,temp);
            }else if (right > left) {
                int temp = left + solve(start,i);
                ans = max(ans,temp);
            } else {
                ans = max(ans, left + max(solve(start,i), solve(i+1,end)));
            }
        }
        return dp[start][end] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        prefix.assign(n+1,0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + stoneValue[i-1];
        }
        dp.assign(n, vector<int>(n,-1));
        return solve(0,n-1);
    }
};