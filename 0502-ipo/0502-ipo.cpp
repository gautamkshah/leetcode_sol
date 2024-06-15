class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++)
        p[i]={profits[i],capital[i]};
        sort(p.begin(),p.end(),comp);
        priority_queue<int>pq;
        int i=0;
        while (k--) {
            while (i < n && p[i].second <= w) {
                pq.push(p[i].first);
                i++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;

    }
};