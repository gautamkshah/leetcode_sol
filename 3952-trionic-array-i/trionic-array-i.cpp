class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        vector<int> diff;
        int n=nums.size();
        for(int i=1;i<n;i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        for(int i=0;i<n-1;i++){
            cout<<diff[i]<<" ";
        }
        int p=0,nn=0,r=0;
        for(int i=0;i<n-1;i++){
            if(diff[i]>0){
                if(nn==0) p++;
                else if(nn>0) r++;
                else return false; 
            }else if(diff[i]<0){
                if(p>0 && r==0) nn++;
                else return false;
            }else return false;
        }
        if(p==0 || nn==0 || r==0) return false;
        return true;
    }
};