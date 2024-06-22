class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        int count=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        if(goal-1<0) return count;
        i=0,j=0,sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal-1 && i<n){
                sum-=nums[i];
                i++;
            }
            count-=(j-i+1);
            j++;
        }
        return count;
        
    }
};

