class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merged;
        int n = occupiedIntervals.size();
        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];
        for(int i = 1; i<n; i++) {
            if(occupiedIntervals[i][0] <= end || end+1 == occupiedIntervals[i][0]) {
                end = max(end,occupiedIntervals[i][1]);
            } else {
                merged.push_back({start,end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }
        merged.push_back({start,end});
        vector<vector<int>> ans;
        for(auto& interval: merged) {
            if(freeStart <= interval[0] && freeEnd >= interval[1]) continue;
            else if(freeStart > interval[0] && freeEnd < interval[1]) {
                ans.push_back({interval[0], freeStart-1});
                ans.push_back({freeEnd+1, interval[1]});
            } else if (freeEnd < interval[0] || freeStart > interval[1]) {
                ans.push_back(interval);
            } else if(freeStart > interval[0] && freeEnd >= interval[1]) {
                ans.push_back({interval[0], freeStart-1});
            }else if(freeEnd < interval[1] && freeStart <= interval[0]){
                ans.push_back({freeEnd+1,interval[1]});
            }
        }
        return ans;

    }
};