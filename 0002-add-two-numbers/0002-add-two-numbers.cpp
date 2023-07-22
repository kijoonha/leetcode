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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l3 = new ListNode();
        ListNode* temp = l3;
        while (l1||l2){
            int sum_two = (l1? l1->val : 0) + (l2? l2->val : 0) + temp->val;
            temp->val = sum_two%10;

            l1 = (l1? l1->next : l1);
            l2 = (l2? l2->next : l2);

            if (l1==nullptr && l2==nullptr&& sum_two/10==0){
                return l3;
            }
            
            temp->next = new ListNode(sum_two/10);
            temp = temp->next;
        }

        return l3;
    }
};