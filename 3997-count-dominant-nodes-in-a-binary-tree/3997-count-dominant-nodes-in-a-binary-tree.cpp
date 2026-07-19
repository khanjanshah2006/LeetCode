/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
TreeNode* copy(TreeNode *node) {
    if(node == nullptr) return nullptr;
    TreeNode* temp = new TreeNode();
    temp->left = copy(node->left);
    temp->right = copy(node->right);

    return temp;
}

int createTree(TreeNode *root1, TreeNode *root2) {
    if(root1 == nullptr) return 0;
    if(root1->left == nullptr && root1->right == nullptr) {
        //leaf node
        root2->val = root1->val;
        return 1;
    }
    int half1 = createTree(root1->left, root2->left);
    int half2 = createTree(root1->right, root2->right);

    int left = (root1->left == nullptr) ? INT_MIN : root2->left->val;
    int right = (root1->right == nullptr) ? INT_MIN : root2->right->val;
    root2->val = max({left,right,root1->val});
    if(root2->val == root1->val) return 1 + half1 + half2;
    return half1+ half2;
}

class Solution {
public:
    int countDominantNodes(TreeNode* root) {
        TreeNode* root2 = copy(root);
        return createTree(root, root2);
    }

};