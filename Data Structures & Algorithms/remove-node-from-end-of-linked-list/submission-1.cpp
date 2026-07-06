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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fill = new ListNode(0, head);
        ListNode* temp = head, *temp2 = fill;

        while(n--) temp = temp->next;
        while(temp != NULL) temp = temp->next, temp2 = temp2->next;

        temp2->next = temp2->next->next;

        return fill->next;
    }
};
