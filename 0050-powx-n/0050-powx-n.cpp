class Solution {
public:
    double myPow(double x, int n) {
        // this is way of the binary exponantation
        // as there is n>0 we give but if power is negetive then loop not eveen run so need to some changes 
        // double ans=1;
        // while(n>0){
        //     if(n%2==1){
        //         ans*=x;
        //     }
        //     x*=x;
        //     n/=2;
        // }
        // return ans;


        //after changes
        // we can also  add  some corner cases tha we know 
        if(n==0)return 1;
        if(x==0)return 0;
        if(x==1)return 1;
        if(x==-1&&n%2==0)return 1;
        if(x==-1&&n%2!=0)return -1;
        double ans=1;
        long binForm=n; //this int of specification long 
        if(n<0){
            x=1/x;
            binForm=-binForm;
            
        }
        while(binForm>0){
            if(binForm%2==1){
                ans*=x;
            }
            x*=x;
            binForm/=2;
        }
        return ans;

    }
};