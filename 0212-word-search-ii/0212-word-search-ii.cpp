class trieNode {
public:
    bool eow;
    string word;
    trieNode *children[26];

    trieNode() {
        eow = false;
        word = "";
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
    }

};



class Solution {
    trieNode *root = new trieNode();
    void insert(string s) {
        trieNode *temp = root;
        for(char ch: s) {
            int idx = ch-'a';
            if(temp->children[idx] == nullptr) {
                temp->children[idx] = new trieNode();
            }
            temp = temp->children[idx];
        }
        temp->eow = true;
        temp->word = s;
    }
    int m,n;
    vector<string> result;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board, int i, int j, trieNode *root) {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(board[i][j] == '$' || root->children[board[i][j]-'a'] == nullptr) return;
        root = root->children[board[i][j]-'a'];
        if(root->eow == true) {
            result.push_back(root->word);
            root->eow = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir : directions) {
            solve(board,i+dir.first,j+dir.second,root);
        }
        board[i][j] = temp;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for(string s: words) {
            insert(s);
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                char c = board[i][j];
                int idx = c- 'a';
                if(root->children[idx] != nullptr) {
                    solve(board,i,j,root);
                }
            }
        }
        return result;
    }
};