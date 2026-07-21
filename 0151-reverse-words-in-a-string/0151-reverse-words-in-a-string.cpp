class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int n = s.length();
        while(i < n) {
            while(i < n && s[i] == ' ') i++;
            string temp;
            while(i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            if(temp.length() == 0) continue;
            words.push_back(temp);
        }
        string ans = "";
        int sz = words.size();
        for(int i = sz-1; i >= 0; i--) {
            ans += words[i];
            if(i > 0) ans += " ";
        }
        return ans;
    }
};