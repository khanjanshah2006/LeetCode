class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i, int rem, vector<vector<int>>& events) {
        if (rem <= 0)
            return 0;
        if (i >= n)
            return 0;
        if (dp[i][rem] != -1)
            return dp[i][rem];
        int ans = 0;
        int idx =
            upper_bound(events.begin() + i + 1, events.end(), events[i][1],
                        [](int value, const vector<int>& event) {
                            return value < event[0];
                        }) -
            events.begin();
        // take
        ans = max(ans, events[i][2] + solve(idx, rem - 1, events));
        // not take
        ans = max(ans, solve(i + 1, rem, events));
        return dp[i][rem] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, events);
    }
};