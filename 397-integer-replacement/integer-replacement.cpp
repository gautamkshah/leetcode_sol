class Solution {
public:
    long int solve(long long int n){
        if(n==1) return 0;
        if(n%2==0) return 1+solve(n/2);
        return 1+min(solve(n-1),solve(n+1));
    }
    int integerReplacement(int n) {
        return solve(n);
        
    }
};