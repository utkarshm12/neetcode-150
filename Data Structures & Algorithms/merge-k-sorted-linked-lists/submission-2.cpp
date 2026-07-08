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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(INT_MIN);

        for(int i = 0; i < lists.size(); i++){
            head = merge(head, lists[i]);
        }
        return head->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* temp1 = head1, *temp2 = head2;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(temp1 != NULL || temp2 != NULL){
            if(temp1 == NULL){
                temp->next = temp2;
                temp2 = temp2->next;
            }
            else if(temp2 == NULL){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
            // cout << temp->val << " -> ";
        }
        // cout << endl;
        return head->next;
    }
};
