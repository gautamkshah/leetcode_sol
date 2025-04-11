class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int sum=0;
        int f1=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            f1+=nums[i]*i;
        }
        ans.push_back(f1);
        cout<<f1<<endl;
        int ma=f1;
        for(int i=1;i<n;i++){
            int f2=f1+sum-n*nums[n-i];
            cout<<f2<<endl;
            ma=max(ma,f2);
            f1=f2;
        }
        return ma;
        
    }
};