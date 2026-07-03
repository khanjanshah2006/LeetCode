class Solution {
public:
    long long mod = 1e9+7;
    vector<long long> dp;
    long long solve(int curLen, int& low, int& high, int& zero, int& one) {
        if(curLen > high) return 0;
        if(dp[curLen] != -1) return dp[curLen];
        bool inRange = false;
        if(curLen >= low && curLen <= high) inRange = true;
        long long take_0 = solve(curLen+zero, low, high, zero, one) % mod;
        long long take_1 = solve(curLen+one , low, high, zero, one) % mod;
        long long ans = (inRange + take_0 + take_1) % mod;
        return dp[curLen] = (ans % mod);
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high+1,-1);
        return solve(0,low, high, zero, one) % mod;
    }
};