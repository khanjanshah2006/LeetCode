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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
        return nullptr;
        ListNode* temp = new ListNode(-1,head);
        ListNode* slow = temp;
        ListNode* fast = temp;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return temp->next;
    }
};