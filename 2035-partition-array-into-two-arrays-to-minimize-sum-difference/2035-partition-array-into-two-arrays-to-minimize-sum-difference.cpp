class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(),nums.end(),0);
        int n1 = n/2;
        int n2 = n-n1;
        unordered_map<int,vector<long long>> mp1;
        for(int mask = 0; mask < (1 << n1); mask++) {
            long long sum = 0;
            for(int i = 0; i < n1; i++) {
                if(mask & (1 << i)) sum += nums[i];
            }
            mp1[__builtin_popcount(mask)].push_back(sum);
        }
        unordered_map<int,vector<long long>> mp2;
        for(int mask = 0; mask < (1 << n2); mask++) {
            long long sum = 0;
            for(int i = 0; i < n2; i++) {
                if(mask & (1 << i)) sum += nums[n1+i];
            }
            mp2[__builtin_popcount(mask)].push_back(sum);
        }
        for(auto& it: mp2) {
            sort(it.second.begin(), it.second.end());
        }
        long long ans = INT_MAX;
        for(auto& it: mp1) {
            int k = it.first;
            int m = n/2 - k;
            for(auto lsum: it.second) {
                long long need = (totalSum - 2*lsum)/2;
                int low = lower_bound(mp2[m].begin(),mp2[m].end(),need)-mp2[m].begin();
                if(low > 0) {
                    ans = min(ans, abs(2*(lsum + mp2[m][low-1])- totalSum));
                }
                if(low < (int)mp2[m].size()) {
                    ans = min(ans, abs(2*(lsum + mp2[m][low])- totalSum));
                }
            }
        }
        return ans;
    }
};