class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        st.push(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            long long val = nums[i];
            // cout<<i<<endl;
            while (true) {
                if (st.empty()) {
                    st.push(val);
                    // cout << i << " " << val << endl;
                    break;
                } else {
                    long long tp = st.top();
                    if (val == st.top()) {
                        st.pop();
                        val *= 2;
                    } else {
                        st.push(val);
                        // cout << i << " " << val << endl;
                        break;
                    }
                }
                // cout << i << " " << val << endl;
            }
        }
        vector<long long> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};