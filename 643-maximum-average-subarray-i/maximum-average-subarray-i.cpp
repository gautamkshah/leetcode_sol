class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
         int sum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        maxi=sum;
        int n=arr.size();
        for(int i=k;i<n;i++){
            sum+=arr[i];
            sum-=arr[i-k];
            maxi=max(maxi,sum);
        }
        return (double)maxi/k;
        
    }
};