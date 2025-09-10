class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& friendships) {
        set<int> st;
        for(auto i:friendships){
            int x=i[0];
            map<int,int> mp;
            for(auto j:lang[x-1]){
                mp[j]=1;
            }
            int y=i[1];
            bool res=false;
            for(auto j:lang[y-1]){
                if(mp[j]==1) res=true;
            }
            if(!res){
                st.insert(x);
                st.insert(y);
            }
        }
        map<int,int> freq;
        int maxi=0;
        for(auto i:st){
            for(auto j:lang[i-1]){
                freq[j]++;
                maxi=max(maxi,freq[j]);
            }
        }
        return st.size()-maxi;
        
    }
};