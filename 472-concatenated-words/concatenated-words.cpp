class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;
        for (string& word : words) {
            int len = word.length();
            vector<bool> dp(len + 1, false);
            dp[0] = true;
            for (int i = 1; i <= len; i++) {
                for (int j = 0; j < i; j++) {
                    if (i == len and j == 0) {
                        continue;
                    }
                    if (dp[j] && st.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[len]) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};