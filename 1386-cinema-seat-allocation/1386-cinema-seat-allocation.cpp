class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> reserved;
        for(auto& seat: reservedSeats) {
            int r = seat[0];
            int s = seat[1];
            reserved[r].push_back(s);
        }
        int ans = (n - reserved.size())*2;
        for(auto& it: reserved) {
            vector<int> state(3,true);
            for(int seat: it.second) {
                if(seat == 2 || seat == 3) state[0] = false;
                else if(seat == 8 || seat == 9) state[2] = false;
                else if(seat == 4 || seat == 5) state[0] = state[1] = false;
                else if(seat == 6 || seat == 7) state[1] = state[2] = false;
            }
            if(state[0] && state[2]) ans += 2;
            else if(state[0] || state[1] || state[2]) ans += 1;
        }
        return ans;
    }
};