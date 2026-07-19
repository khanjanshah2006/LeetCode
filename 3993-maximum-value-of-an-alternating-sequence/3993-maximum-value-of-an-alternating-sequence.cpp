class Solution {
public:
    typedef long long ll;
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        ll N = (n-1)/2;
        ll ans = s + (ll)N*(m-1);
        if(n % 2 == 0) {
            ans += m;
        }else {
            ans += 1;
        }
        return ans;
    }
};