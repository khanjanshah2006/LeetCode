class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int ans = 0;
        for(int sc = 0; sc < n; sc++) {
            for(int j = sc; j < n; j++) {
                unordered_map<int,int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int i = 0; i < m; i++) {
                    sum += matrix[i][j] - ((sc > 0) ? matrix[i][sc-1] : 0);
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};