class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        while( j < n) {
            char ch = s[j];
            if(mp.find(ch) != mp.end() && mp[ch] >= i) {
                i = mp[ch]+1;
            }
            mp[ch] = j;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};