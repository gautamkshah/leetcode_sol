class Solution {
public:
    string convert(string s, int n) {
        int size=s.size();
        int index=2*n-2;
        if(index==0) return s;
        string ans;
        for(int i=0;i<n;i++){
            int j=i;
            while(j<size){
                ans.push_back(s[j]);
                if((j%index!=0&&j%index!=n-1)&&(j+index-2*(j%index))<size) 
                ans.push_back(s[j+index-2*(j%index)]);
                j+=index;

            }
        }
        return ans;
        
    }
};