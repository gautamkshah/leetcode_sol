class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
      
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        for(int i=1;i<n;i++){
            pre[i]=max(h[i-1],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(h[i+1],suff[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(pre[i],suff[i])-h[i]);
        }
        return ans;
        //  5 8  2 6  10 15 16 20 
        //  2 6 5 8 10 15 16 20

           
        
    }
};