class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        long long  c1=0,c2=0;
        long long  q=0,w=0;
        for(int i=0;i<n1;i++){
            c1+=nums1[i];
            if(nums1[i]==0) q++;
        }
        for(int i=0;i<n2;i++){
            c2+=nums2[i];
            if(nums2[i]==0) w++;
        }
        long long int res1=c1+q;
        long long int res2=c2+w;
        if(res1>res2){
           long long  int ans1=res1-c2;
            if(w==0) return -1;
            return res1;
        }
        else if(res1==res2){
            return res1;
        }
        else{
            long long int ans1=res2-c1;
            if(q==0) return -1;
            return res2;
        }
        
    }
};