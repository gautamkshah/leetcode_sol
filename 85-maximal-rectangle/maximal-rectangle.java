class Solution {
    public int maximalRectangle(char[][] mat) {
        int n=mat.length;
        int m=mat[0].length;
        int[] h=new int[m];
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0'){
                    h[j]=0;
                }else{
                    h[j]++;
                }
            }
            ans=Math.max(ans,largestRectangleArea(h));
        }
        return ans;
    }
        public int largestRectangleArea(int[] heights) {
            Stack<Integer> st= new Stack<>();
            int n=heights.length;
            int[] nser= new int[n];
            int[] nsel= new int[n];
            for(int i=n-1;i>=0;i--){
                while(!st.isEmpty() && heights[st.peek()]>=heights[i]){
                    st.pop();
                }
                if(st.isEmpty()){
                    nser[i]=n;
                }else{
                    nser[i]=st.peek();
                }
                st.push(i);
            }
            while(!st.isEmpty()){
                st.pop();
            }
            for(int i=0;i<n;i++){
                while(!st.isEmpty() && heights[st.peek()]>=heights[i]){
                    st.pop();
                }
                if(st.isEmpty()){
                    nsel[i]=-1;
                }else{
                    nsel[i]=st.peek();
                }
                st.push(i);
            }
            int ans=0;
            for(int i=0;i<n;i++){
                int h=heights[i];
                int w=nser[i]-nsel[i]-1;
                ans=Math.max(ans,h*w);
            }
            return ans;



    }
}