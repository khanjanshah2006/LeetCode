class CountIntervals {
    int Count;
    set<pair<int,int>> st;
public:
    CountIntervals() {
        Count = 0;
    }
    
    void add(int left, int right) {
        auto it = st.upper_bound({left,INT_MAX});
        if(it != st.begin()) {
            auto prev_it = prev(it);
            if(prev_it->second >= left) {
                it = prev_it;
            }
        }
        while(it != st.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right,it->second);
            Count -= (it->second - it->first + 1);
            it = st.erase(it);
        }
        st.insert({left,right});
        Count += right-left+1;
    }
    
    int count() {
        return Count;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */