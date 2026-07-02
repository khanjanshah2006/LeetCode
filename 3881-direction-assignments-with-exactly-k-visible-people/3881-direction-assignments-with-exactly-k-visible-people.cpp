class Solution {
public:
    long long mod = 1e9 + 7;
    vector<long long> fact;
    vector<long long> invfact;

    long long power(long long a, long long x) {
        if (x == 0)
            return 1;
        long long half = power(a, x / 2);
        long long result = (half * half) % mod;
        if (x % 2 == 1) {
            result = (result * (a % mod)) % mod;
        }
        return result;
    }
    long long comb(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        long long ans = fact[n];
        ans = (ans * invfact[r]) % mod;
        ans = (ans * invfact[n - r]) % mod;
        return ans;
    }

    int countVisiblePeople(int n, int pos, int k) {

        fact.assign(n + 1, 1);
        invfact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invfact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        }
        long long ans = 0;
        for (int x = 0; x <= k; x++) {
            long long way = (comb(pos, x) * comb(n - 1 - pos, k - x)) % mod;
            ans = (ans + way) % mod;
        }
        return (ans * 2) % mod;
    }
};