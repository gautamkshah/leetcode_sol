class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int l=0,r=n-1;
        int area=0;
        while(l<=r){
            int ar=min(h[l],h[r])*(r-l);
            area=max(area,ar);
            if(h[l]<h[r]){
                l++;
            }else{
                r--;
            }
        }
        return area;
    }
};