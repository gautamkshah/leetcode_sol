class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> freq;
         vector<int> fre;
        for(int i=0;i<word.size();i++){
            freq[word[i]]++;
        }
        
        int mi = INT_MAX;
        for (const auto& pair : freq) {
            fre.push_back(pair.second);
        }
        sort(fre.begin(), fre.end(), greater<int>());
        
       
        for (int i = 0; i < fre.size(); ++i) {
            int target = fre[i];
            int c = 0;
            for (int f : fre) {
                if (f > target + k) {
                    c += f - (target + k);
                } else if (f < target) {
                c += f;
                }
            }
            mi = min(mi, c);
            
            if (mi == 0) {
                break;
            }
        }
        
        return (mi == INT_MAX) ? 0 : mi;
        
        
    }
};