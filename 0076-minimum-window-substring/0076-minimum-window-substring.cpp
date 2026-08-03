class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>S;
        unordered_map<char,int> T;
        for(char c: t) T[c]++;
        int n1 = s.length();
        int n2 = t.length();
        int j = 0;
        int i = 0;
        int valid = 0;
        int len = INT_MAX;
        int start = 0;

        for(; j < n1; j++) {
            S[s[j]]++;
            if(T[s[j]] != 0 && T[s[j]] >= S[s[j]]) valid++;
            if(valid == n2) {
                while(T[s[i]] == 0 || S[s[i]] > T[s[i]]){
                    S[s[i]]--;
                    i++;
                }
                if(j-i+1 < len) {
                    len = j-i+1;
                    start = i;
                }
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(start,len);
    }
};