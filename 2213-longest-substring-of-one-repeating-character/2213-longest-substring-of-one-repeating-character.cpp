struct Node {
    int maxLen;
    int lsum;
    int rsum;
    char lchar;
    char rchar;
};

class SegmentTree {
public:
    int n;
    vector<Node> tree;
    string s;
    SegmentTree(string& str) {
        s = str;
        n = s.size();
        tree.assign(4*n, Node());
        build(1,0,n-1);
    }

    Node merge(Node& L, Node& R, int Llen, int Rlen) {
        Node ans;
        ans.maxLen = max(L.maxLen, R.maxLen);
        if(L.rchar == R.lchar) {
            ans.maxLen = max(ans.maxLen, L.rsum + R.lsum);
        }  
        ans.lchar = L.lchar;
        ans.rchar = R.rchar;
        ans.lsum = L.lsum;
        ans.rsum = R.rsum;
        if(L.lsum == Llen && L.lchar == R.lchar) {
            ans.lsum = L.lsum + R.lsum;
        }
        if(R.rsum == Rlen && R.rchar == L.rchar) {
            ans.rsum = R.rsum +L.rsum;
        }
        return ans;
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node].maxLen = tree[node].lsum = tree[node].rsum = 1;
            tree[node].lchar = tree[node].rchar = s[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = merge(tree[2*node],tree[2*node+1],mid-l+1,r-mid);
    }

    void update(int node, int l, int r, int idx, char val) {
        if(l == r) {
            tree[node].lchar = tree[node].rchar = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid) {
            update(2*node,l,mid,idx,val);
        }else {
            update(2*node+1,mid+1,r,idx,val);
        }
        tree[node] = merge(tree[2*node], tree[2*node + 1], mid-l+1,r-mid);
    }

    int queryMax() {
        return tree[1].maxLen;
    }
};


class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryIndices.size();
        vector<int> ans;
        SegmentTree st(s);
        for(int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char val = queryCharacters[i];
            st.update(1,0,n-1,idx,val);
            ans.push_back(st.queryMax());
        }
        return ans;
    }
};