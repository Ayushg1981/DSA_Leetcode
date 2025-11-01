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
    ListNode* reverse(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* ans=new ListNode(100);
        ListNode* temp2=ans;
        ans->next=head;
        int x=0;
        while(temp1){
            x++;
            temp1=temp1->next;
        }
        temp1=head;
        while(x>=k){
            x-=k;
            temp1=temp2->next;
            if(temp1==NULL) break;
            for(int i=0;i<k-1;i++) temp1=temp1->next;
            ListNode* temp3=temp1->next;
            temp1->next=NULL;
            temp1=temp2->next;
            temp2->next=NULL;
            ListNode* temp4=temp1;
            temp1=reverse(temp1);
            temp2->next=temp1;
            temp4->next=temp3;
            temp2=temp4;
        }
        return ans->next;
    }
};