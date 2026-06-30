class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> pairs;
        int n = weights.size();
        for (int i = 1; i < n; i++) {
            pairs.push_back(weights[i] + weights[i - 1]);
        }
        sort(pairs.begin(), pairs.end());
        long long ans = 0;
        n = pairs.size();
        for (int i = 0; i < k - 1; i++) {
            ans += pairs[n - i - 1] - pairs[i];
        }
        return ans;
    }
};