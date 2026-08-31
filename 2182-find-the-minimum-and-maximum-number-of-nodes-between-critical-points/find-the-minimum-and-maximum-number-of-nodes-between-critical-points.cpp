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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last  = -1, curr = 1;
        int mn = INT_MAX, mx = INT_MIN;
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp){
            if(temp->next == NULL){
                temp = temp->next;
                continue;
            }
            
            if((temp->val > prev->val && temp->val > temp->next->val) || (temp->val < prev->val && temp->val < temp->next->val)){
                cout<<curr<<" ";
                if(first == -1){
                    first = curr;
                    last = curr;
                }
                else{
                    mn = min(curr - last, mn);
                    mx = curr - first;
                }

                last = curr;
            }
            prev = temp;
            temp = temp->next;
            curr++;
        }

        if(last == first)return {-1,-1};
        else return {mn,mx};
    }
};