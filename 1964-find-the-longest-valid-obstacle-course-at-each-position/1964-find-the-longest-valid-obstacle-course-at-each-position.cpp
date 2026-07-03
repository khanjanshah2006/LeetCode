class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> tails;
        for(int i = 0; i < n ; i++) {
            int idx = upper_bound(tails.begin(),tails.end(),obstacles[i]) - tails.begin();
            if(idx == tails.size()) {
                tails.push_back(obstacles[i]);
            } else {
                tails[idx] = obstacles[i];
            }
            ans[i] = idx+1;
        }
        return ans;
    }
};