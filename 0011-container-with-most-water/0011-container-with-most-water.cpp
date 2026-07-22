class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i,j;
        i = 0; j = n-1;
        int ans = INT_MIN;
        while( i < j) {
            if(height[i] <= height[j]) {
                ans = max(ans, (j-i)*height[i]);
                i++;
            } else {
                ans = max(ans, (j-i)*height[j]);
                j--;
            }
        }
        return ans;
    }
};