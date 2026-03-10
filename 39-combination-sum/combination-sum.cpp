class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> candid,int tar,int i,vector<int> vec){
        int n=candid.size();
        if(i==n){
            if(tar==0){
                ans.push_back(vec);
            }
            return;
        }
        if(candid[i]<=tar){
            vec.push_back(candid[i]);
            solve(candid,tar-candid[i],i,vec);
            vec.pop_back();
        }
        solve(candid,tar,i+1,vec);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candid, int tar) {
        vector<int> vec;
        solve(candid,tar,0,vec);
        return ans;
    }
};