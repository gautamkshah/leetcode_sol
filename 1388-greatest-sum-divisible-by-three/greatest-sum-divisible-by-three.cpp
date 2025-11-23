class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int> one,two;
        int sum=0;
        for(auto i:nums){
            if(i%3==1){
                one.push_back(i);
            }else if(i%3==2){
                two.push_back(i);
            }
            sum+=i;
        }
        if(sum%3==0){
            return sum;
        }
        // cout<<sum<<endl;
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        if(sum%3==1){
            int ans1=0;
            if(one.size()>0){
                ans1=sum-one[0];
            }
            int ans2=0;
            if(two.size()>=2){
                ans2=sum-two[0]-two[1];
            }
            return max(ans1,ans2);
        }
        int ans1=0;
        if(two.size()>=1){
            ans1=sum-two[0];
        }int ans2=0;
        if(one.size()>1){
            ans2=sum-one[0]-one[1];
        }
        return max(ans1,ans2);
    }
};
// 1 8
// 2 
// 23
// 