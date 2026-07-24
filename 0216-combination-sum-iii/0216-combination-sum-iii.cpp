class Solution {
public:
    vector<vector<int>> ans;
    int K, N;

    void solve(int i, int sum, vector<int>& temp) {
        if (temp.size() == K) {
            if (sum == N) {
                ans.push_back(temp);
            }
            return;
        }
        if (sum > N)
            return;
        for (int digit = i; digit <= 9; digit++) {
            temp.push_back(digit);
            solve(digit + 1, sum + digit, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        K = k;
        N = n;
        vector<int> temp;
        solve(1, 0, temp);
        return ans;
    }
};