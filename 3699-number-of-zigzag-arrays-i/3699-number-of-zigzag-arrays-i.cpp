class Solution {
public:
    long long mod = 1e9 + 7;
    // 0 - down 1- up
    int dp[2001][2001][2];
    int solve(int i, int x, bool dir, int& n, int& l, int& r) {
        if (i == n)
            return 1;
        if (dp[i][x][dir] != -1)
            return dp[i][x][dir];
        long long ans = 0;
        if (dir) { // up
            // for (int y = x + 1; y <= r; y++) {
            //     ans = (ans + solve(i + 1, y, !dir, n, l, r)) % mod;
            // }

            if (x + 1 <= r) {
                ans = (ans + solve(i + 1, x + 1, !dir, n, l, r) +
                       solve(i, x + 1, dir, n, l, r)) %
                      mod;
            }

        } else { // down
            // for (int y = x - 1; y >= l; y--) {
            //     ans = (ans + solve(i + 1, y, !dir, n, l, r)) % mod;
            // }

            if (x - 1 >= l) {
                ans = (ans + solve(i + 1, x - 1, !dir, n, l, r) +
                       solve(i, x - 1, dir, n, l, r)) %
                      mod;
            }
        }
        return dp[i][x][dir] = ans;
    }

    int zigZagArrays(int n, int l, int r) {
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = l; j <= r; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        for (int x = l; x <= r; x++) {
            ans = (ans + solve(1, x, true, n, l, r)) % mod;
            ans = (ans + solve(1, x, false, n, l, r)) % mod;
        }
        return ((ans % mod) + mod) % mod;
    }
};