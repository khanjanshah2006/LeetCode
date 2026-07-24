class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq; 
    int curr;
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(!pq.empty()) {
            int ans = pq.top();
            pq.pop();
            st.erase(ans);
            return ans;
        }
        int ans = curr;
        curr++;
        return ans;
    }
    
    void addBack(int num) {
        if(num < curr && st.find(num) == st.end()) {
            pq.push(num);
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */