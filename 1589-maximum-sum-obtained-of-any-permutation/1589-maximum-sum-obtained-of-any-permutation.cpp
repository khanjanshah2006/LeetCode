class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        long long mod = 1e9+7;
        vector<int> diff(n+1,0);
        for(auto& req: requests) {
            diff[req[0]]++;
            diff[req[1]+1]--;
        }
        int count = 0;
        vector<int> freq;
        for(int i=0; i<n ; i++) {
            count += diff[i];
            freq.push_back(count);
        }
        sort(freq.begin(),freq.end());
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            sum += ((long long)nums[i] * (long long)freq[i])%mod;
        }
        return sum % mod;

    }
};