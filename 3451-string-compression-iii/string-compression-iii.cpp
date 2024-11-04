class Solution {
public:
    string compressedString(string word) {
        string temp="";
    int n=word.size();
    int i=0;
    int c=0;
    while(i<n){
        char ch=word[i];
        c=0;
        while(i<n && word[i]==ch && c<9){
            c++;
            i++;
        }
        temp+=to_string(c)+ch;
    }
    return temp;
        
        
    }
};