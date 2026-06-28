class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        int end = points[0][1];
        int n = points.size();
        for(int i=1; i<n; i++) {
            if(points[i][0] <= end) {
                end = min(end, points[i][1]);
            } else {
                ans++;
                end = points[i][1];
            }
        }
        return ans+1;
    }
};