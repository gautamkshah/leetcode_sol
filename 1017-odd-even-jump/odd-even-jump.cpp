class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = even[n - 1] = true; 
        map<int, int> valToIndex;      
        valToIndex[arr[n - 1]] = n - 1;

        int result = 1;

        for (int i = n - 2; i >= 0; --i) {
            
            auto it = valToIndex.lower_bound(arr[i]);
            if (it != valToIndex.end()) {
                odd[i] = even[it->second];
            }

            
            auto jt = valToIndex.upper_bound(arr[i]);
            if (jt != valToIndex.begin()) {
                --jt;
                even[i] = odd[jt->second];
            }

            if (odd[i])
                result++;

            valToIndex[arr[i]] = i; 
        }

        return result;
    }
};