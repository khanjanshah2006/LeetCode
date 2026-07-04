class Solution {
public:
    vector<unordered_map<int,int>> dp;

    int solve(int i, int prev, vector<int>&arr1, vector<int>& arr2) {
        if(i == arr1.size()) return 0;
        if(dp[i].find(prev) != dp[i].end()) {
            return dp[i][prev];
        }

        int ans = INT_MAX;
        if(arr1[i] > prev) {
            ans = min(ans, solve(i+1,arr1[i],arr1,arr2));
        }
        auto idx = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
        if(idx != arr2.size()) {
            int opr = solve(i+1,arr2[idx],arr1,arr2);
            if(opr != INT_MAX) {
                ans = min(ans, 1 + opr);
            }
        }
        return dp[i][prev] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        dp.resize(arr1.size());
        set<int> st(arr2.begin(),arr2.end());
        vector<int> arr(st.begin(),st.end());
        int ans = solve(0,INT_MIN,arr1,arr);
        return (ans == INT_MAX) ? -1: ans;
    }
};