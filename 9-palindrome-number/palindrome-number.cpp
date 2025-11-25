class Solution {
public:
    bool isPalindrome(int x) {
        long long int n=x;
        long long int q=0;
        while(x>0){
            //cout<<x%10<<endl;
            q=(q*10)+(x%10);
            x/=10;
        }
        //cout<<q<<endl;
        if(q==n){
            return true;
        }else{
            return false;
        }
    }
};