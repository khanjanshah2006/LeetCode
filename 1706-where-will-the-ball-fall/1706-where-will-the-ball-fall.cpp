class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n, -1);
        int m = grid.size();
        for (int i = 0; i < n; i++) {
            int r = -1;
            int c = i;
            while (r != m - 1) {
                if (c - 1 >= 0 && grid[r + 1][c - 1] == -1 &&
                    grid[r + 1][c] == -1) {
                    c = c - 1;
                } else if (c < n - 1 && grid[r + 1][c] == 1 &&
                           grid[r + 1][c + 1] == 1) {
                    c = c + 1;
                } else {
                    break;
                }
                r++;
            }
            if (r == m - 1)
                ans[i] = c;
        }
        return ans;
    }
};