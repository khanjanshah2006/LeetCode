class Solution {
public:
    vector<int> getRow(int rowindex) {
        vector<int> ans(rowindex+1);
        long long val = 1;
        for  (int i = 0; i <= rowindex/2; i++) {
            ans[i] = ans[rowindex - i] = val;
            val = (val * (rowindex - i))/ (i+1) ;
        }
        return ans;
    }
};