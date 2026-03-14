class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }else{
                right[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }else{
                left[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int w=right[i]-left[i]-1;
            int area=w*h[i];
            ans=max(ans,area);
        }
        return ans;

    }
};