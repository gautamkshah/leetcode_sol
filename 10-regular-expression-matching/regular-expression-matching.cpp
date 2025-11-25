class Solution {
public:
    bool rec(int i,int j,string &s,string &p){
     //   cout<<i<<" "<<j<<" "<<endl;
        if(i<0 && j<0) return true;
        else if(j<0) return false;
        else if(i<0){
            for(int k=j;k>=0;k=k-2){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(s[i]==p[j] || p[j]=='.'){
          //  cout<<i<<" "<<j<<endl;
            return rec(i-1,j-1,s,p);
        }
        else if(p[j]=='*'){
            if(s[i]==p[j-1] || p[j-1]=='.')
                return rec(i,j-2,s,p) || rec(i-1,j,s,p);
            else return rec(i,j-2,s,p);
            //}else return rec(i,j-2,s,p);
            
        }
        else return false;

    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return rec(n-1,m-1,s,p);
    }
};