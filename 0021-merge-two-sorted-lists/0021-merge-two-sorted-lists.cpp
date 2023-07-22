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
int MAXNUM = 9999;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* list3 = new ListNode();
        ListNode* tmp = list3;
        if (list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        while (getVal(list1)!=MAXNUM || getVal(list2)!=MAXNUM){
            tmp->next = new ListNode();
            tmp = tmp->next;
            if (getVal(list1)<getVal(list2)){
                tmp->val = getVal(list1);
                list1 = list1->next;
            }
            else{
                tmp->val = getVal(list2);
                list2 = list2->next;
            }
        }
        return list3->next;
    };
        
private:
    int getVal(ListNode *list1){
        if(list1 == nullptr){
            return MAXNUM;
        }
        else{
            return list1->val;
        }
    };
};