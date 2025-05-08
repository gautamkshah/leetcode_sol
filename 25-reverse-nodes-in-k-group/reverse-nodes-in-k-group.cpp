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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        int c=0;
        ListNode* prev=dummy, *curr= dummy, *nextt=dummy;
        while(curr->next!=NULL){
            c++;
            curr=curr->next;
        }

        while(c>=k){
            curr=prev->next;
            nextt=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nextt->next;
                nextt->next=prev->next;
                prev->next=nextt;
                nextt=curr->next;
            }
            prev=curr;
            c-=k;
        }
        return dummy->next;

    }
};