class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n+1,0);
        for(auto& shift: shifts) {
            int val = (shift[2] == 1) ? 1 : -1;
            diff[shift[0]] += val;
            diff[shift[1]+1] -= val;
        }
        int curSum = 0;
        for(int i=0; i<n; i++) {
            curSum += diff[i];
            int net_shift = ((curSum % 26) + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        return s;
    }
};