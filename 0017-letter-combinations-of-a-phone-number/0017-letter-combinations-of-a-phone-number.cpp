class Solution {
public:
    vector<string> ans;
    unordered_map<char,vector<char>> adj;
    int n;
    void dfs(int i, string s, string curr) {
        if(i == n) {
            ans.push_back(curr);
            return;
        }
        for(auto& c: adj[s[i]]) {
            curr += c;
            dfs(i+1,s,curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        adj['2'] = {'a','b','c'};
        adj['3'] = {'d','e','f'};
        adj['4'] = {'g','h','i'};
        adj['5'] = {'j','k','l'};
        adj['6'] = {'m','n','o'};
        adj['7'] = {'p','q','r','s'};
        adj['8'] = {'t','u','v'};
        adj['9'] = {'w','x','y','z'};
        n = digits.size();
        dfs(0,digits,"");
        return ans;
    }
};