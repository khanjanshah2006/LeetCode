class Solution {
public:
    typedef long long ll;
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n/2;
        int n2 = n - n1;
        vector<ll> arrA(1LL << n1);
        for(int mask = 0; mask < (1 << n1); mask++) {
            ll sum = 0;
            for(int i = 0; i < n1; i++) {
                if(mask & (1 << i)) sum += nums[i];
            }
            arrA[mask] = sum;
        }    
        vector<ll> arrB(1LL << n2);
        for(int mask = 0; mask < (1 << n2); mask++) {
            ll sum = 0;
            for(int i = 0; i < n2; i++) {
                if(mask & (1 << i)) sum += nums[n1+i];
            }
            arrB[mask] = sum;
        }
        sort(arrB.begin(),arrB.end());
        int ans = INT_MAX;
        for(ll s: arrA) {
            ll need = goal - s;
            auto lo = lower_bound(arrB.begin(),arrB.end(),need)-arrB.begin();
            if(lo > 0) {
                int sum2 = arrB[lo-1];
                int total = s + sum2;
                ans = min(ans,abs(total-goal));
            }
            if(lo < arrB.size()) {
                int sum2 = arrB[lo];
                int total = s + sum2;
                ans = min(ans, abs(total-goal));
            }
        }
        return ans;
    }
};