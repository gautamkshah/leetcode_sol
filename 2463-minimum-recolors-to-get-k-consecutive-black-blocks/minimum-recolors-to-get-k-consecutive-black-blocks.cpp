class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n = b.size();
        int countW = 0;
        
        for (int i = 0; i < k; i++) {
            if (b[i] == 'W') countW++;
        }
        
        int minW = countW; 
        
        for (int i = k; i < n; i++) {
            if (b[i - k] == 'W') countW--; 
            if (b[i] == 'W') countW++; 
            minW = min(minW, countW);
        }
        
        return minW;
    }
};
