class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> add(n),sub(n);
        for(int i=0;i<n;i++){
            add[i]=values[i]+i;
            sub[i]=values[i]-i;
        }
        vector<int> maxi(n),mini(n);
        maxi[0]=add[0];
        mini[n-1]=sub[n-1];
        for(int i=1;i<n;i++){
            maxi[i]=max(maxi[i-1],add[i]);
        }
        for(int i=n-2;i>=0;i--){
            mini[i]=max(mini[i+1],sub[i]);
        }
      

        int val=0;
        for(int i=0;i<n-1;i++){
            val=max(val,(add[i]+mini[i+1]));
        }
        return val;

        
    }
};