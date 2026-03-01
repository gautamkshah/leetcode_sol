class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        string cpy=s;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                cpy.pop_back();
            }else{
                return cpy;
            }
        }
        return cpy;
    }
};