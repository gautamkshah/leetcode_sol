class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        s.push_back('(');
        int c=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    c++;
                    if(s[i+1]==')'){
                        i++;
                    }else{
                        c++;
                    }
                }
                else if(s[i+1]==')'){
                    st.pop();
                    i++;
                }else{
                    c++;
                    st.pop();
                }
            }
        }
        return c+2*st.size();
    }
};