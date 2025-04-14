class Solution {
public:
    bool solve(vector<int> &mat,int tar,int ind,int a,int b,int c,int d){
        if(a==tar && b==tar && c==tar && d==tar) return true;
        if(a>tar || b>tar || c>tar || d>tar) return false;
        bool res=false;
        res=res|| solve(mat,tar,ind+1,a+mat[ind],b,c,d);
        if(res) return true;
        res=res|| solve(mat,tar,ind+1,a,b+mat[ind],c,d);
        if(res) return true;
        res=res|| solve(mat,tar,ind+1,a,b,c+mat[ind],d);
        if(res) return true;
        res=res|| solve(mat,tar,ind+1,a,b,c,d+mat[ind]);
        return res;

    }
    bool makesquare(vector<int>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            sum+=mat[i];
        }

        if(sum%4!=0){
            return false;
        }
        if(mat[n-1]>sum/4) return false;
        sort(mat.begin(),mat.end(),greater<int>());
        return solve(mat,sum/4,0,0,0,0,0);
        
    }
};