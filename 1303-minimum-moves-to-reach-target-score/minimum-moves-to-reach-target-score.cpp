class Solution {
public:
    int minMoves(int target, int m) {
        int c=0;
        while(target!=1){
            if(target%2==0){
                if(m>0){
                    m--;
                    target/=2;
                    c++;
                }else{
                    c+=target-1;
                    target=1;
                }
            }else{
                c++;
                target--;
            }
        }
        return c;
    }
};