class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        int lt=days[n-1];
        vector<int> costTillDay(lt+1,0);
        costTillDay[0]=0;
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(days[i]);
        }
        for(int i=1;i<=lt;i++){
            if(st.find(i)==st.end()){
                costTillDay[i]=costTillDay[i-1];
                continue;
            }
            int oneDay=cost[0]+costTillDay[max(0,i-1)];
            int sevenDay=cost[1]+costTillDay[max(0,i-7)];
            int ThirtyDay=cost[2]+costTillDay[max(0,i-30)];
            costTillDay[i]=min({oneDay,sevenDay,ThirtyDay});
        }
        return costTillDay[lt];
    }
};