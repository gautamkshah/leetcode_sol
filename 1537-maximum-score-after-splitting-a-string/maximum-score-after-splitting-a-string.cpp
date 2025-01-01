class Solution {
public:
    int maxScore(string s) {
        int n =s.length();
                int cnto=0, cntz=0, maxi=INT_MIN, o=0, z=0;
                        for(int i=0;i<n;i++){
                                    if(s[i]=='0') z++;
                                                else o++;
                                                        }
                                                                int i=0;
                                                                        while(i<n){
                                                                                    if(s[i]=='0'){
                                                                                                    cntz++;
                                                                                                                    maxi=max(maxi,(cntz+(o-cnto)));
                                                                                                                                }
                                                                                                                                            else{
                                                                                                                                                            cnto++;
                                                                                                                                                                            maxi=max(maxi,(cntz+(o-cnto)));
                                                                                                                                                                                        }
                                                                                                                                                                                                    i++;
                                                                                                                                                                                                                if(i==n-1) break;
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                return maxi;
        
    }
};