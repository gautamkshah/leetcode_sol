class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90){
                temp+=s[i]+32;
            }else if(s[i]>=48 && s[i]<=57){
                temp+=s[i];
            }else if(s[i]>=97 && s[i]<=122){
                temp+=s[i];
            }
        }
        string rec=temp;
        reverse(temp.begin(),temp.end());
        return(rec==temp);
        
    }
};