class Solution {
public:

    bool valid(vector<int>& arr ,int n,int h, long long mBanana) {
        int hour=0;

        int i=0;

        while(i<n) {
            if(arr[i]>mBanana) {
                if(arr[i]%mBanana==0) {
                    hour+=arr[i]/mBanana;
                    i++;
                }else{
                    hour+=(arr[i]/mBanana)+1;
                    i++;
                }
            }else {
                hour++;
                i++;
            }

            if(hour>h) {
                return false;
            }
        }
        return true;

    }


    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();

        long long sum=0;

        for(int i=0;i<n;i++) {
            sum+=arr[i];
        }

        long long str=1;

        long long end=sum;

        long long ans;


        while(str<=end) {
            long long mid=str+(end-str)/2;


            if(valid(arr,n,h,mid)) {
                ans=mid;
                end=mid-1;
            }else {
                str=mid+1;
            }
        }
        return ans;
    }
};