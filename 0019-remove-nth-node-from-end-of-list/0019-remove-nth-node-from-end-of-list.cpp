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
        int len = findLength(head, 0);
        ListNode* curr=head;
        ListNode* pre;
        for(int i = len-n ; i>0 ; i--){
            pre = curr;
            curr = curr->next;    
        }
        
        if(len==1){
            return NULL;
        }
        
        if(len==n){
            return head->next;
        }

        pre->next = curr->next;       
        return head;
        
    }

private:
    int findLength(ListNode* head, int len){
        if (head == nullptr){
            return len;
        }
        return findLength(head->next, len+1);
    }
};

