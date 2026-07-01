class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startend(n+1,0);
        for(int i=0 ;i<=n; i++) {
            int left = max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);

            startend[left] = max(startend[left], right);
        }
        int ans = 0;
        int maxend = 0;
        int curend = 0;
        for(int i=0; i<=n; i++) {
            if(i > maxend) return -1;
            if(i > curend) {
                ans++;
                curend = maxend;
            }
            maxend = max(maxend,startend[i]);
        }
        return ans;
    }
};