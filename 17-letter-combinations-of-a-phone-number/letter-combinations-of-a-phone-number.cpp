class Solution {
public:
    vector<string> vec;
    void solve(int i,string &digits, map<int,string>&mp, string cur){
        if(i==digits.size()){
            vec.push_back(cur);
            return;
        }
        string st=mp[digits[i]-'0'];
        for(char j:st){
            solve(i+1,digits,mp,cur+j);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        solve(0,digits,mp,"");
        return vec;

    }
};