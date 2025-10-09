class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        for (auto& b : bt) {
            swap(b[0], b[1]);
        }

        // Sort in descending order (now sorts by units first)
        sort(bt.begin(), bt.end(), greater<vector<int>>());

        int ans = 0;
        for (auto& b : bt) {
            int units = b[0], boxes = b[1];
            int take = min(ts, boxes);
            ans += take * units;
            ts -= take;
            if (ts <= 0)
                break;
        }
        return ans;
    }
};
