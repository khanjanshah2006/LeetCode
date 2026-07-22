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
    void reverseLL(ListNode *head,ListNode*toAttach) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        toAttach->next = prev;
    }
    int lengthLL(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            n++;
            temp = temp->next;
        }
        return n;
    }
    int pairSum(ListNode* head) {
        int n = lengthLL(head);
        ListNode* temp = head;
        for(int i=1; i < n/2; i++) {
            temp = temp->next;
        }
        reverseLL(temp->next, temp);
        temp = temp->next;
        ListNode* temp1 = head;
        int ans = INT_MIN;
        for(int i=1; i<=n/2; i++) {
            ans = max(ans, temp->val + temp1->val);
            temp = temp->next;
            temp1 = temp1->next;
        }
        return ans;
    }
};