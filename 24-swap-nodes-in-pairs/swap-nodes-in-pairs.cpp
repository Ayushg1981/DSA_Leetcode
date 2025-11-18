class Solution {
public:
    void f(ListNode* t1,ListNode* t2,ListNode* t3,ListNode* t4){
        if(t1==NULL || t2==NULL || t3==NULL) return; 
        t2->next=t4;
        t3->next=t2;
        t1->next=t3;
        if(t4 && t4->next) f(t2,t4,t4->next,t4->next->next);
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=new ListNode(100);
        a->next=head;
        f(a,head,head->next,head->next->next);
        return a->next;
    }
};