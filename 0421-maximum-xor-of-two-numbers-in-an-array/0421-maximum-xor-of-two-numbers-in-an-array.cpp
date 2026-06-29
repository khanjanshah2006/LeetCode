class Node{
public: 
    Node *children[2];
    Node() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};
class Solution {
private: 
    Node *root = new Node();
    int n;

    void insert(int num) {
        Node *temp = root;
        for(int i=30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(temp->children[bit] == nullptr) {
                temp->children[bit] = new Node();
            }
            temp = temp->children[bit];
        }
    }

    int findMax(int num) {
        int ans = 0;
        Node *temp = root;
        for(int i=30; i>=0 ;i--) {
            int bit = !((num >> i) & 1);
            if(temp->children[bit] != nullptr) {
                ans += (1<<i);
                temp = temp->children[bit];
                continue;
            }
            temp = temp->children[!bit];
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        n = nums.size();
        for(auto &num: nums) {
            insert(num);
        }
        int ans = INT_MIN;
        for(auto &num: nums) {
            ans = max(ans, findMax(num));
        }
        return ans;
    }
};