class Solution {
public:
	vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size();
        int n = colCosts.size();
        int startR = min(startPos[0],homePos[0]);
        int endR = max(startPos[0],homePos[0]);
        int cost = 0;
        for(int i = startR; i <= endR; i++) {
        	cost += rowCosts[i];
        }
        int startC = min(startPos[1],homePos[1]);
        int endC = max(startPos[1],homePos[1]);
        for(int i = startC; i <= endC; i++) {
        	cost += colCosts[i];
        }
        cost -= (rowCosts[startPos[0]] + colCosts[startPos[1]]);
        return cost;
    }
};