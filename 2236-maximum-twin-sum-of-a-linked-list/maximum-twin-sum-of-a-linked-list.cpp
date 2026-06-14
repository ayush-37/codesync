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
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        len/=2;
        ListNode* prev = NULL, *nxt = NULL;
        ListNode* curr = head;
        while(len--){
            curr = curr->next;
        }
        ListNode* revHead;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            revHead = curr;
            curr = nxt;
        }

        temp = head;
        int ans = INT_MIN;
        while(temp && revHead){
            ans = max(ans,temp->val + revHead->val);
            temp = temp->next;
            revHead = revHead->next;
        }
        return ans;
    }
};