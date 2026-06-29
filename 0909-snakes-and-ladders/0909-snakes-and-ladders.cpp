class Solution {
public:
    int n;
    pair<int,int> getCoord(int num) {
        int row = (n-1) - ((num-1)/n);
        int col = (num-1)%n;
        if(row % 2 == n % 2) {
            col = n-1 - col;
        }
        return {row,col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<bool> visited(n*n+1, false);
        q.push(1);
        visited[1] = true;
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int num = q.front();
                q.pop();
                if(num == n*n) return level;;
                for(int i = 1; i <= 6; i++) {
                    if(num+i > n*n) break;
                    if(visited[num+i]) continue;
                    visited[num+i] = true;
                    pair<int,int> p = getCoord(num+i);    
                    if(board[p.first][p.second] != -1) {
                        q.push(board[p.first][p.second]);
                    } else {
                        q.push(num+i);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};