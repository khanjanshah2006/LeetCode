class Solution {
public:
    int n;
    void reverse(vector<vector<int>>& grid, int i, int j) {
        while(i < j) {
            swap(grid[i/n][i%n], grid[j/n][j%n]);
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        n = grid[0].size();
        int N = m*n;
        k = k%N;
        reverse(grid,0,N-1);
        reverse(grid, 0, k-1);
        reverse(grid, k, N-1);
        return grid;
    }
};