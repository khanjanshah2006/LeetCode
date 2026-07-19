class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t;
        int freq_x;
        int freq_y;
        freq_x = freq_y = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == x) freq_x++;
            else if(s[i] == y) freq_y++;
            else {
                t += s[i];
            }
        }
        while(freq_y--) t += y;
        while(freq_x--) t += x;
        return t;
    }
};