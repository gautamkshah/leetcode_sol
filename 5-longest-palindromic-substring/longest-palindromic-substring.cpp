class Solution {
public:
  //  int n;
   
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> v(n,vector<int> (n,0));
        int m=0;
        int maxl=0;
        string ans;
        for(int k=0;k<n;k++){
            for(int i=0,j=i+k;j<n;j++,i++){
                if(i==j){
                    v[i][j]=1;
                }
                else if(k==1 && s[i]==s[j]){
                    v[i][j]=2;
                }
                else{
                    if(s[i]==s[j] && v[i+1][j-1]>0){
                        v[i][j]=v[i+1][j-1]+2;
                    }
                }
                if(v[i][j]>0){
                    if(j-i+1>maxl){
                        maxl=j-i+1;
                        ans=s.substr(i,maxl);
                    }

                }
            }
        }
        return ans;
    
        
    }
};












