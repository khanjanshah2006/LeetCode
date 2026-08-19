class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> reserved;
        for(auto& seat: reservedSeats) {
            int r = seat[0];
            int s = seat[1];
            reserved[r] |= (1 << s);
        }
        int ans = (n - reserved.size())*2;
        for(auto& it: reserved) {
            vector<bool> state(3,true);
            state[0] = !(it.second & (0b0000111100));
            state[1] = !(it.second & (0b0011110000));
            state[2] = !(it.second & (0b1111000000));
            if(state[0] && state[2]) ans += 2;
            else if(state[0] || state[1] || state[2]) ans += 1;
        }
        return ans;
    }
};