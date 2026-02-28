class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int i=0,j=mat.size()-1;
        int n=mat.size();
        int m=mat[0].size();
        while(i<=j){
            int mid=(i+j)/2;
            if(mat[mid][0]<=tar && tar<=mat[mid][m-1]){
                int l=0,h=m-1;
                while(l<=h){
                    int mid2=(l+h)/2;
                    if(mat[mid][mid2]==tar){
                        return true;
                    }else if(mat[mid][mid2]<tar){
                        l=mid2+1;
                    }else{
                        h=mid2-1;
                    }
                }
                return false;
            }else if(mat[mid][0]>tar){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return false;
        
    }
};