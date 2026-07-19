class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastseen(26);
        for(int i = 0 ; i < n; i++) lastseen[s[i]-'a'] = i;

        vector<bool> visited(26,false);
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(visited[s[i]-'a']) continue;
            while(!st.empty() && s[i] < st.top() && lastseen[st.top()-'a'] > i) {
                visited[st.top()-'a'] = false;
                st.pop();
            }
            visited[s[i]-'a'] = true;
            st.push(s[i]);
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};