class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> num(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(i==0) num[i][j]=nums[j];
                else{
                    num[i][j]=(num[i-1][j]+num[i-1][j+1])%10;
                }
            }
        }
        return num[n-1][0];
    }
};