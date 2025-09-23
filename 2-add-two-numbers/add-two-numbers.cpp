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
        int x=0; 
        ListNode* temp=l1; 
        ListNode* prev=NULL; 
        while(l1 && l2){ 
            x=l1->val+l2->val+x; 
            l1->val=x%10; 
            x=x/10; 
            prev=l1; 
            l1=l1->next; 
            l2=l2->next; 
        } 
        if(l2){ 
            prev->next=l2; 
            l1=l2; 
        } 
        while(l1){ 
            x=l1->val+x; 
            l1->val=x%10; 
            x=x/10; 
            prev=l1; 
            l1=l1->next; 
        }
        if(x>0){ 
            ListNode* a=new ListNode(1); 
            prev->next=a;
        }
        return temp;
    }
};