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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *head1 = head;
        ListNode *head2 = head->next;
        ListNode *ptr1 = head1;
        ListNode *ptr2 = head2;

        ListNode *temp = head->next->next;
        bool odd = true;
        while(temp != nullptr) {
            if(odd) {
                ptr1->next = temp;
                ptr1 = ptr1->next;
            } else {
                ptr2->next = temp;
                ptr2 = ptr2->next;
            }
            temp = temp->next;
            odd = !odd;
        }
        ptr2->next = nullptr;
        ptr1->next = head2;
        return head1;
    }
};