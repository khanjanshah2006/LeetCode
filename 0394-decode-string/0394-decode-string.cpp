class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == ']') {
                string temp = "";
                while(!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.pop();
                string numStr = "";
                while(!st.empty() && (st.top() <= '9' && st.top() >= '0')) {
                    numStr += st.top();
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int times = stoi(numStr);
                string toAdd = "";
                while(times--) {
                    toAdd += temp;
                }
                for(char c: toAdd) st.push(c);
            } else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};