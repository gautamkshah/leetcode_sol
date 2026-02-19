class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        // Find the initial median iterator
        // For k=4, it points to index 2 (3rd element). For k=5, it points to index 2 (3rd element).
        auto mid = next(window.begin(), k / 2);
        
        vector<double> result;
        auto getMedian = [&]() {
            if (k % 2 != 0) return (double)*mid;
            // If even, average mid and the element right before it
            return ((double)*mid + *prev(mid)) * 0.5;
        };

        result.push_back(getMedian());

        for (int i = k; i < nums.size(); ++i) {
            // 1. Insert new element
            window.insert(nums[i]);
            if (nums[i] < *mid) {
                mid--; // New element pushed the median to the left
            }

            // 2. Remove outgoing element
            int outNum = nums[i - k];
            if (outNum <= *mid) {
                // If the outgoing number is the median or smaller, 
                // we must move mid to the right before erasing to stay valid.
                mid++; 
            }
            
            // Standard multiset::erase(val) removes ALL instances of val.
            // We use find() to get an iterator to exactly ONE instance.
            window.erase(window.find(outNum));

            // 3. Final alignment
            // Because k/2 logic varies, we might need to adjust by one step
            // to ensure 'mid' is at the correct index for the getMedian() logic.
            // (Note: The specific logic above handles most cases; this is the simplified version)

            result.push_back(getMedian());
        }

        return result;
    }
};