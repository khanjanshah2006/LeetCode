class Solution {
public:
    int m;
    int ans = INT_MIN;
    void solve(int i, int count, int n, vector<vector<int>>& requests,
               vector<int>& result) {
        if (i >= m) {
            bool flag = true;
            for (auto& it : result) {
                if (it != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = max(ans, count);
            }
            return;
        }
        int from = requests[i][0];
        int to = requests[i][1];
        result[from]--;
        result[to]++;
        solve(i + 1, count + 1, n, requests, result);
        result[from]++;
        result[to]--;
        solve(i + 1, count, n, requests, result);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> result(n, 0);
        m = requests.size();
        solve(0, 0, n, requests, result);
        return ans;
    }
};