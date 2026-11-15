class Solution {
public:
    int climbStairs(int n) {
        if(n<0){
            return 0;
        }
        if(n==1 || n==2){
            return n;
        }

        int a=1; // 1 step
        int b=2; // 2step
        int c=3; // 3step

        for(int i=3;i<=n;i++){
            c=b+a;
            a=b;
            b=c;
        }
        return c;
    }
};