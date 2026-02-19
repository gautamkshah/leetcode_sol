#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    ordered_set window;
    vector<double> result;

    for (int i = 0; i < nums.size(); ++i) {
        
        window.insert({nums[i], i});

        if (window.size() >= k) {
            
            if (k % 2 != 0) {
                result.push_back(window.find_by_order(k / 2)->first);
            } else {
               
                double m1 = window.find_by_order(k / 2)->first;
                double m2 = window.find_by_order(k / 2 - 1)->first;
                result.push_back((m1 + m2) / 2.0);
            }

           
            window.erase({nums[i - k + 1], i - k + 1});
        }
    }
    return result;
}
};