class Node {
public:
    Node* children[26];
    vector<string> words;
    Node() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    Node* root;
    Solution() {
        root = new Node();
    }
    void Insert(string s) {
        Node* temp = root;
        for(char c: s) {
            int idx = c - 'a';
            if(temp->children[idx] == nullptr) {
                temp->children[idx] = new Node();
            }
            temp = temp->children[idx];
            if(temp->words.size() < 3) temp->words.push_back(s);
        }
    }


    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for(string s: products) {
            Insert(s);
        }
        vector<vector<string>> ans;
        Node* temp = root;
        for(char c: searchWord) {
            int idx = c - 'a';
            if(temp->children[idx] == nullptr) {
                temp->children[idx] = new Node();
            }
            temp = temp->children[idx];
            ans.push_back(temp->words);
        }
        return ans;
    }
};