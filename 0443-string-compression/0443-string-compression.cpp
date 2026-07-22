class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 0;
        while(i  < n) {
            char ch = chars[i];
            int cnt = 0;
            while(i < n && chars[i] == ch) {
                i++;
                cnt++;
            }
            chars[j] = ch;
            j++;
            if(cnt > 1) {
                string size = to_string(cnt);
                for(char c: size) {
                    chars[j++] = c;
                }
            }
        }
        return j;
    }
};