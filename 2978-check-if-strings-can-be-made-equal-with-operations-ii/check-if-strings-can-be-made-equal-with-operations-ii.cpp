class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        string a="";
        string b="";
        string c="";
        string d="";
        for(int i=0;i<n;i=i+2){
            a+=s1[i];
        }
         for(int i=0;i<n;i=i+2){
            b+=s2[i];
        }
         for(int i=1;i<n;i=i+2){
            c+=s1[i];
        }
         for(int i=1;i<n;i=i+2){
            d+=s2[i];
        }
        sort(a.begin(),a.end());
         sort(b.begin(),b.end());
         sort(c.begin(),c.end());
         sort(d.begin(),d.end());
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(a==b && d==c) return true;
        return false;
        
    }
};