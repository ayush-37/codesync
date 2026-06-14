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
    int pairSum(ListNode* head) {
        int len = 0;
        ListNode* slow = head,*fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow, *prev = NULL, *nxt;
        ListNode* revHead;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            revHead = curr;
            curr = nxt;
        }

        ListNode* temp = head;
        int ans = INT_MIN;
        while(temp && revHead){
            ans = max(ans,temp->val + revHead->val);
            temp = temp->next;
            revHead = revHead->next;
        }
        return ans;
    }
};