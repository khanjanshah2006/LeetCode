class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            if(st.empty() || asteroids[i]  >= 0) st.push(asteroids[i]);
            else {
                while(!st.empty() && st.top() < -asteroids[i] && st.top() >= 0) {
                    st.pop();
                }
                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                else if (st.top() == -asteroids[i]) st.pop();
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};