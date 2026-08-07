class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char c: s) {
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto& it: mp) {
            pq.push({it.second,it.first});
        }
        string ans = "";
        int prevChar = '0';
        int prevFreq = 0;
        while(!pq.empty()) {
            int currChar = pq.top().second;
            int currFreq = pq.top().first;
            pq.pop();
            ans += currChar;
            if(prevChar != '0' && prevFreq > 0) {
                pq.push({prevFreq,prevChar});
            }
            prevFreq = currFreq-1;
            prevChar = currChar;
        }
        if(ans.length() != s.length()) return "";
        return ans;
    }
};