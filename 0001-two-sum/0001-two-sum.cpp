class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        //sort(a.begin(),a.end());
        vector<int> v;
        int n=a.size();
        for(int i=0;i<n;i++){
            int s=t-a[i];
            
            int it = find(a.begin()+i+1, a.end(), s)-a.begin();
           // cout<<it<<" "<<i<<" "<<s<<endl;
            //cout<<i<<endl;
            if(it!=n){
                v.push_back(i);
                v.push_back(it);
                break;
            }
        }
        return v;

    }
};