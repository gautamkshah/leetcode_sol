class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int copy=x;
        long int rev=0;
        while(x>0){
            rev=rev*10+x%10;
            x/=10;
        }
        if(copy==rev) return true;
        else return false;
        
    }
};