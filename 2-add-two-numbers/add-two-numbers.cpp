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
        vector<int> v;
        vector<int> b;
        while(l1!=NULL){
            v.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            b.push_back(l2->val);
            l2=l2->next;
        }
      //  reverse(v.begin(),v.end());
       // reverse(b.begin(),b.end());
        int c=0;
        vector<int> ans;
        int n=min(v.size(),b.size());
        for(int i=0;i<n;i++){
            int val=v[i]+b[i]+c;
            c=val/10;
            val=val%10;
            ans.push_back(val);
        }
        if(v.size()>b.size()){
            for(int i=n;i<v.size();i++){
                 int val=v[i]+c;
                   c=val/10;
                   val=val%10;
                   ans.push_back(val);
            }
        }
        else  if(v.size()<b.size()){
            for(int i=n;i<b.size();i++){
                 int val=b[i]+c;
                   c=val/10;
                   val=val%10;
                   ans.push_back(val);
            }
        }if(c!=0){
             ans.push_back(c);
        }
      //  reverse(ans.begin(),ans.end());
       
        ListNode *l=new ListNode(0);
         ListNode *de=l;
        for(int i=0;i<ans.size();i++){
             ListNode *lq=new ListNode(ans[i]);
             l->next=lq;
             l=l->next;
        }
        return de->next;;
        
    }
};