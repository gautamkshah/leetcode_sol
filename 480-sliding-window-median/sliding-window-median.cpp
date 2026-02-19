class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st(nums.begin(), nums.begin() + k);
        auto it = next(st.begin(), k / 2);
        vector<double> ans;
        auto getMedian =[&](){
            if(k%2!=0) return (double)*it;
            else return ((double)*it + *prev(it))*0.5;
        };
        ans.push_back(getMedian());
        for (int i = k; i < n; i++) {
            st.insert(nums[i]);
            if (nums[i] < *it) {
                it--;
            }
            int ot = nums[i - k];
            if (ot <= *it) {
                it++;
            }
            st.erase(st.find(ot));
            ans.push_back(getMedian());
        }
        return ans;
    }
};