class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt1 = 0;
        int cnt0 = 0;
        int ans = 0;
        for(char c: s) {
            int num = c-'0';
            if(num == 0) cnt0++;
            else cnt1++;
            if(abs(cnt1-cnt0) <= 1) ans++;
        }
        return ans;
    }
};