class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int l=0;
        int h=n*n+1;
        while(l<=h){
            int mid=(l+h)/2;
            vector<vector<int>> vis(n,vector<int>(m,0));
            queue<pair<int,int>> q;
            q.push({0,0});
            vis[0][0]=1;
            bool found=false;
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 && y==m-1){
                    found=true;
                    break;
                }
                for(pair<int,int> pq: vector<pair<int,int>>{{1,0},{-1,0},{0,1},{0,-1}}){
                    int dx=pq.first;
                    int dy=pq.second;
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]<=mid){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            if(found) h=mid-1;
            else l=mid+1;
        }
        return max(l,grid[0][0]);
    }
};