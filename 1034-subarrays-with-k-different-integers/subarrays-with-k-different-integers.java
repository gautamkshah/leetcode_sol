class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    private int atmost(int[] nums,int k){
        int left=0,count=0;
        HashMap<Integer,Integer> map= new HashMap<>();
        for(int right=0;right<nums.length;right++){
            map.put(nums[right],map.getOrDefault(nums[right],0)+1);
            while(map.size()>k){
                int l=nums[left];
                map.put(l,map.get(l)-1);
                if(map.get(l)==0){
                    map.remove(l);
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
}