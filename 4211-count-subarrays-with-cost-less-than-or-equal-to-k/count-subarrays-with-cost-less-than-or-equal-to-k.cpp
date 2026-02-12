class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long count=0;
        deque<long long> dq1,dq2;
        long long l=0;
        for(long long i=0;i<n;i++){
            while(!dq1.empty() && nums[dq1.back()]<nums[i]){
                dq1.pop_back();
            }
            dq1.push_back(i);
            while(!dq2.empty() && nums[dq2.back()]>nums[i]){
                dq2.pop_back();
            }
            dq2.push_back(i);
            long long val=(nums[dq1.front()]-nums[dq2.front()])*(i-min(dq1.front(),dq2.front()));
            while(l<=i && (i-l+1)*(nums[dq1.front()]-nums[dq2.front()])>k){
                if(dq1.front()==l){
                    dq1.pop_front();
                }
                if(dq2.front()==l){
                    dq2.pop_front();
                }
                l+=1;
               

            }
             count+=i-l+1;
           

        }
         return count;
    }
};