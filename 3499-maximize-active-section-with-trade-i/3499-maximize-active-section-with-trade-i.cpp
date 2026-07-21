class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int total1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') total1++;
        }
        vector<int> zeros;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int j = i;
                while(j < n && s[j] == '0') j++;
                zeros.push_back(j-i);
                i = j;
            } else {
                i++;
            }
        }
        int ans = 0;
        for(int i = 1; i < zeros.size(); i++) {
            ans = max(ans, zeros[i]+zeros[i-1]);
        }
        return ans + total1;
    }
};