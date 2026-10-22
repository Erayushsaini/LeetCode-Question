class Solution {
public:

    bool valid(vector<int>& arr,int n,int d,int maxW) {
        int days=1;

        int w=0;

        for(int i=0;i<n;i++) {
            if((w+arr[i])>maxW) {
                days++;
                w=arr[i];
            }else {
                w+=arr[i];
            }
        }

        return days<=d;

    }
    int shipWithinDays(vector<int>& arr, int days) {
        
        int n=arr.size();
        int sum=0;
        int m=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            m=max(m,arr[i]);
        }

        int str=m;

        int end=sum;


        int ans=0;

        while(str<=end) {
            int mid=str+(end-str)/2;


            if(valid(arr,n,days,mid)) {
                end=mid-1;
                ans=mid;
            }else {
                str=mid+1;
            }
        }

        return ans;
    }
};