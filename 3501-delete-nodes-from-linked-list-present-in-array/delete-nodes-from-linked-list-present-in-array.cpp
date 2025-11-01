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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int m=-1;
        for(int i=0;i<nums.size();i++){
            m=max(m,nums[i]);
        }
        vector<bool> v(m+1,false);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]=true;
        }
        ListNode* a=new ListNode(100);
        ListNode* temp=a;
        while(head){
            if(head->val>m || !v[head->val]){
                temp->next=head;
                temp=temp->next;
            }
            head=head->next;
        }
        temp->next=NULL;
        return a->next;
    }
};