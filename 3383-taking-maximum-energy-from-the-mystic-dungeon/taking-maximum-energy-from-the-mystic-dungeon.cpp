class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=energy[n-1];
        // vector<int> ans(n,0);
        for(int i=n-k-1;i>=0;i--){
            energy[i]+=energy[i+k];
        }
        for(int i=0;i<n;i++){
            ans=max(energy[i],ans);
        }
        return ans;
    
        
    }
};