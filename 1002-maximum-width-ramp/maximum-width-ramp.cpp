class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(nums[i]<nums[st.top()]){
                st.push(i);
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                ans=max(ans,i-st.top());
                st.pop();
            }
        }
        return ans;
        
    }
};