class Solution {
public:
    int dp[6][2][2];
    string num;
    int solve(int i, bool tight, bool changed) {
        if(i == num.size()) return changed;
        if(dp[i][tight][changed] != -1) return dp[i][tight][changed];
        
        int ans = 0;
        int limit = tight ? num[i]-'0' : 9;
        for(int digit = 0; digit <= limit; digit++) {
            bool newtight = tight && (digit == limit);
            if(digit == 3 || digit == 4 || digit == 7) continue;
            bool flag = (digit == 2 || digit == 5 || digit == 6 || digit == 9);
            ans += solve(i+1,newtight, changed || flag);
        }
        return dp[i][tight][changed] = ans;
    }

    int rotatedDigits(int n) {
        num = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false);
    }
};