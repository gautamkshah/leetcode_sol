class Solution {
public:
    vector<vector<string>> vec;
    bool pal(string temp){
    int l = 0, r = temp.size() - 1;
    while(l < r){
        if(temp[l] != temp[r]) return false;
        l++;
        r--;
    }
    return true;
}
    void solve(string &s, int in,vector<string> &res){
        if(in==s.size()){
            vec.push_back(res);
        }
        string temp="";
        for(int i=in; i<=s.size(); i++){
            temp.push_back(s[i]);
            if(pal(temp)){
                res.push_back(temp);
                solve(s,i+1,res);
                res.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        solve(s,0,res);
        return vec;
    }
};