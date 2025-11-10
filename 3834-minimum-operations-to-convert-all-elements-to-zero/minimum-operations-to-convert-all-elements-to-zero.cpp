class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() && nums[i] == 0) {
            i++;
        }
        int n = nums.size();
        if (i == n)
            return 0;
        int op = 0;
        stack<int> st;

        int j = n - 1;
        while (nums[j] == 0) {
            j--;
        }

        st.push(nums[i]);
        int k = i;
        for (i = k + 1; i <= j; i++) {
            while (!st.empty() && st.top() > nums[i]) {
                st.pop();
                op++;
            }
            if (!st.empty() && st.top() == nums[i]) {
                continue;
            } else {
                st.push(nums[i]);
            }
        }
        int c=0;
        while(!st.empty()){
            if(st.top()!=0){
                c++;
            }
            st.pop();
        }
        op += c;
        return op;
    }
};