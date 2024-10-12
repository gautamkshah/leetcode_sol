class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int cc = 0;
        vector<int> in(n, 0);
        vector<vector<int>> g(n);
        for (auto i : pre) {
            int p = i[1];
            int c = i[0];
            g[p].push_back(c);
            in[c]++;
        }
        queue<int> s;
        for (int i = 0; i < n; i++) {
            if(in[i]==0) 
            s.push(i);
        }
        while(!s.empty()){
            int c=s.front();
            s.pop();
            cc++;
            for(auto i: g[c]){
                in[i]--;
                if(in[i]==0) s.push(i);
            }
        }
        if(cc==n) return true;
        else return false;
    }
};