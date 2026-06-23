class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> Col;
    unordered_set<int> NegDia; // r-C
    unordered_set<int> PosDia; // r+c

    void solve(vector<string>& board, int r, const int& n) {
        if(r == n) {
            result.push_back(board);
            return;
        }
        for(int c=0; c < n; c++) {
            if(Col.count(c) || NegDia.count(r-c) || PosDia.count(r+c)) continue;
            board[r][c] = 'Q';
            Col.insert(c);
            NegDia.insert(r-c);
            PosDia.insert(r+c);

            solve(board, r+1, n);

            Col.erase(c);
            NegDia.erase(r-c);
            PosDia.erase(r+c);
            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return result;
    }
};