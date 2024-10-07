class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    void solve(string &s,int ii,string &ss){
        int n=s.size();
        if(ii==n){
            ans.push_back(ss);
            return ;
        }
        string temp="";
        for(int i=ii;i<n;i++){
            temp=temp=temp+s[i];
            if(st.find(temp)!=st.end()){
                string word=ss;
                word=word+temp;
                if(i!=n-1){
                    word=word+' ';
                }
                solve(s,i+1,word);
            }
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string ss="";
        for(auto i:wordDict){
            st.insert(i);
        }
        solve(s,0,ss);
        
        return ans;
    }
};