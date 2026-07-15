class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> room(n,0);
        priority_queue<int, vector<int>, greater<int>> unused;        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> running;
        for(int i = 0; i < n; i++) unused.push(i);
        for(auto meeting: meetings) {
            int start = meeting[0];
            int end = meeting[1];

            while(!running.empty() && start >= running.top().first) {
                unused.push(running.top().second);
                running.pop();
            }
            if(!unused.empty()) {
                int toUse = unused.top();
                unused.pop();
                running.push({end,toUse});
                room[toUse]++;
            } else {
                auto [delayedEnd, toUse] = running.top();
                running.pop();
                running.push({end + delayedEnd - start , toUse});
                room[toUse]++;
            }
        }
        int ans = 0;
        int MaxUsed = room[0];
        for(int i = 1; i < n; i++) {
            if(room[i] > MaxUsed) {
                ans = i;
                MaxUsed = room[i];
            }
        }        
        return ans;
    }
};