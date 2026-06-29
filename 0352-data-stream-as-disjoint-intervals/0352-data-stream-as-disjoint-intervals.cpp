class SummaryRanges {
    map<int,int> mp;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;
        auto it = mp.upper_bound(value);
        if(it != mp.begin()) {
            auto prev_it = prev(it);
            if(prev_it->second + 1 >= left) {
                it = prev_it;
            }
        }
        while(it != mp.end() && right+1 >= it->first) {
            left = min(it->first,left);
            right = max(it->second, right);
            it = mp.erase(it);
        }
        mp[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for(auto& it: mp) {
            result.push_back({it.first, it.second});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */