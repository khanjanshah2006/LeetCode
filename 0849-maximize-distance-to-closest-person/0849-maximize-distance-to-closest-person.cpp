class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> occupied;
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) 
                occupied.push_back(i);
        }
        int sz = occupied.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(seats[i] == 0) {
                int temp;
                int next = upper_bound(occupied.begin(),occupied.end(),i)-occupied.begin();
                int before = next-1;
                if(next == sz) {
                    //no next seat
                    temp = abs(i-occupied[before]);
                }else if(next == 0) {
                    //no prev seat
                    temp = abs(i - occupied[next]);
                }else {
                    temp = min(abs(i-occupied[before]), abs(i-occupied[next]));
                }
                ans = max(temp,ans);
            }
        }
        return ans;
    }
};