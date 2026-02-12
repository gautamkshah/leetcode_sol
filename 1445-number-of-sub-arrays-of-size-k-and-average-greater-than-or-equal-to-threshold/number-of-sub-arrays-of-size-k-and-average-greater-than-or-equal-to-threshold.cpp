class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int c=0,s=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(i+1-k>0){
                s-=arr[i-k];
            }
            if(s>=th*k && i>=k-1){
                c++;
            }
            cout<<s<<endl;
        }
        return c;
        
    }
};