class PalindromeQuery {
    vector<int> P;
public:
    PalindromeQuery(string s) {
        int n = s.length();
        string T = "@#";
        for(int i = 0; i < n; i++) {
            T += s[i];
            T += '#';
        }
        T += "$";
        int m = T.length();
        P.assign(m,0);
        int C = 0; int R = 0;
        for(int i = 1; i < m; i++) {
            int mirror = 2*C-i;
            if(i < R) {
                P[i] = min(R-i,P[mirror]);
            }
            while(T[i+1+P[i]] == T[i-1-P[i]]) {
                P[i]++;
            } 
            if(i+P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
    }

    bool isPalindrome(int l, int r) {
        if(l > r) return false;
        int c = l+r+2;
        int len = r-l+1;
        return P[c] >= len;
    }
};


class Solution {
public:
    vector<vector<int>> adj;

    vector<int> startIdx;
    vector<int> endIdx;
    string Rootdfs;

    void dfs(int i,const string& s) {
        startIdx[i] = Rootdfs.size();
        for(int v: adj[i]) {
            dfs(v,s);
        }
        Rootdfs += s[i];
        endIdx[i] = Rootdfs.size()-1;
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        startIdx.assign(n,0);
        endIdx.assign(n,0);
        dfs(0,s);
        PalindromeQuery pq(Rootdfs);

        vector<bool> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = pq.isPalindrome(startIdx[i],endIdx[i]);
        }
        return ans;
    }
};