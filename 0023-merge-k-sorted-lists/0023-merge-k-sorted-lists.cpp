/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;
        while(a && b) {
            if(a->val <= b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        if(a) curr->next = a;
        else curr->next = b;
        return temp->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int n = lists.size();
        for(int i=1; i < n; i++) {
            lists[i] = merge(lists[i-1], lists[i]);
        }
        return lists[n-1];
    }
};