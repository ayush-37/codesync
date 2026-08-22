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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int> v;
        int cnt = 1;
        while(temp && cnt <= right){
            if(cnt >= left && cnt <= right)v.push_back(temp->val);
            temp = temp->next;
            cnt++;
        }

        temp = head;
        cnt = 1;

        while(temp && cnt <= right){
            if(temp && cnt >= left && cnt <= right){
                temp->val = v.back();
                v.pop_back();
            }
            temp = temp->next;
            cnt++;
        }
        
        return head;
    }
};