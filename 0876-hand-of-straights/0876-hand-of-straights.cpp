class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int,int> mp;
        set<int> st;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
            st.insert(hand[i]);
        }
        
        for(auto i:st){
            if(mp.find(i)!=mp.end()){
            int y=i;
            int c=mp[i];
            cout<<"hrk\n";
            for(int j=0;j<k;j++){
                if(mp.find(y+j)!=mp.end() && mp[y+j]>=c){
                    mp[y+j]-=c;
                    if(mp[y+j]==0) mp.erase(y+j);
                }else return false;
            }
            }
        }
        return true;
    
    }
};