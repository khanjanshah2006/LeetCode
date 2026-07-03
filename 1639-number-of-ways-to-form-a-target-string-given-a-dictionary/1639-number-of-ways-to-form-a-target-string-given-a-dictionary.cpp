class Solution {
public:
    int m, n, sz;
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp;
    long long solve(int i, int j, vector<unordered_map<char, int>>& mp,
                    string& target) {
        if (i >= sz)
            return 1;
        if (j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long take = 0;
        if (mp[j].find(target[i]) != mp[j].end()) {
            take = (1LL * mp[j][target[i]] * solve(i + 1, j + 1, mp, target)) %
                   mod;
        }
        long long notTake = solve(i, j + 1, mp, target) % mod;
        long long result = (take + notTake) % mod;
        return dp[i][j] = result;
    }

    int numWays(vector<string>& words, string target) {
        m = words.size();
        n = words[0].length();
        sz = target.length();
        dp.assign(sz + 1, vector<long long>(n + 1, -1));
        vector<unordered_map<char, int>> mp(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[j][words[i][j]]++;
            }
        }
        return solve(0, 0, mp, target);
    }
};