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
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast->next && fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow->next == NULL && fast->next == NULL)return NULL;
        if(fast->next == NULL){
            prev->next = slow->next;
            slow->next = NULL;
        }
        else{
            ListNode* temp = slow->next->next;
            slow->next->next = NULL;
            slow->next = temp;
        }
        return head;

    }
};