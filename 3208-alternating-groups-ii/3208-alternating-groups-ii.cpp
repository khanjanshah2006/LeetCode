class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0; i < k-1; i++) {
            colors.push_back(colors[i]);
        }
        int i = 0;
        int j = 1;
        int ans = 0;
        int n = colors.size();
        while( j < n) {
            if(colors[j-1] == colors[j]) {
                i = j;
                j++;
                continue;
            }
            if(j-i+1 == k) {
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};