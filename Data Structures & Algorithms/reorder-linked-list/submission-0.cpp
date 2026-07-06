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
    void reorderList(ListNode* head) {
        ListNode* temp1 = head, *temp2 = head;

        while(temp2 != NULL && temp2->next != NULL && temp2->next->next != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }

        ListNode* temp = temp1->next, *cur, * prev = NULL;
        temp1->next = NULL;

        while(temp != NULL){
            cur = temp->next;
            temp->next = prev;
            prev = temp;
            temp = cur;
        }

        temp1 = head, temp2 = prev;
        ListNode* cur1, *cur2;

        while(temp2 != NULL){

            cur1 = temp1->next;
            cur2 = temp2->next;

            temp1->next = temp2;
            temp2->next = cur1;

            temp1 = cur1;
            temp2 = cur2;
        }

    }
};
