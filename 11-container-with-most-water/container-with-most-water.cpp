class Solution {
public:
    int maxArea(vector<int>& he) {
        int n=he.size();
        int i=0,j=n-1;
        int ma=0;
        while(i<j){
            int val=min(he[i],he[j]);
            //cout<<val<<endl;
            ma=max(val*(j-i),ma);
            if(he[i]<he[j]){
                i++;
            }else{
                j--;
            }
        }
        return ma;
    }
};