class Solution:
    def findBestValue(self, arr: list[int], target: int) -> int:
        l=0
        r=max(arr)
        ans1=0 # just smaller
        ans2=0 # just bigger
        while(l<=r):
            mid=(l+r)//2 # value 
            tsum=0
            for i in arr:
                tsum+=min(mid,i)
            diff=target-tsum
            if diff>=0:
                ans1=mid
                l=mid+1
            else:
                r=mid-1
            # print(mid, tsum)
        
        l=0
        r=max(arr)   
        while(l<=r):
            mid=(l+r)//2 # value 
            tsum=0
            for i in arr:
                tsum+=min(mid,i)
            diff=tsum-target
            if diff>=0:
                ans2=mid
                r=mid-1
            else:
                l=mid+1
   
        tsum1,tsum2=0,0
        for i in arr:
            tsum1+=min(ans1,i)
            tsum2+=min(ans2,i)
       
        
        if abs(target-tsum1)<=abs(target-tsum2):
            return ans1
        return ans2

        