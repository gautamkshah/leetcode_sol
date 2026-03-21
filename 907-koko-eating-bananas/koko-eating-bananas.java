class Solution {
    public int minEatingSpeed(int[] piles, int hh) {
        int l=1;
        int h=0;
        for(int i=0;i<piles.length;i++){
            h=Math.max(h,piles[i]);
        }
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
        long  time=0;
            for(int i=0;i<piles.length;i++){
                time+=(piles[i]+mid-1)/mid;
            }
            if(time<=hh){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
        
    }
}