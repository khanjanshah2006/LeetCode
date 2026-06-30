class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n-1;
        int top = 0;
        int down = n-1;

        vector<vector<int>> ans(n,vector<int>(n));
        int count = 1;
        int dir = 0;
        while(top <= down && left <= right) {
            if(dir == 0) {
                for(int i=left; i <= right; i++) {
                    ans[top][i] = count;
                    count++;
                }
                top++;
            }
            if(dir == 1) {
                for(int i= top; i<=down; i++) {
                    ans[i][right] = count;
                    count++;
                }
                right--;
            }
            if(dir == 2) {
                for(int i=right; i>=left; i--) {
                    ans[down][i] = count;
                    count++;
                }
                down--;
            }
            if(dir == 3) {
                for(int i = down; i >= top; i--) {
                    ans[i][left] = count;
                    count++;
                }
                left++;
            }

            dir = (dir+1)%4;
        }
        return ans;
    }
};