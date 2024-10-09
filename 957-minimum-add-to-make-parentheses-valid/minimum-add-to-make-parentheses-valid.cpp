class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int cnt=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty()) cnt++;
                else if(st.top()=='('){
                    st.pop();
                }else{
                    cnt++;
                }
            }
        }
        cnt+=st.size();
        return cnt;
        
    }
};