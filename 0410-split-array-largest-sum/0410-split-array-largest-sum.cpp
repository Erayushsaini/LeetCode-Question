class Solution {
public:

    bool valid(vector<int>& nums,int n,int maxSum, int k) {
        int subarray=1;

        int sum=0;

        for(int i=0;i<n;i++) {
            if((sum+nums[i])>maxSum) {
                subarray++;
                sum=nums[i];
            }else {
                sum+=nums[i];
            }
        }

        return subarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int str=0;
        for(int i=0;i<n;i++) {
            str=max(str,nums[i]);
            sum+=nums[i];
        }
        int end=sum;
        int ans=-1;
        if(k>n) {
            return ans;
        }
        while(str<=end) {
            int mid=str+(end-str)/2;

            if(valid(nums,n,mid,k)) {
                ans=mid;
                end=mid-1;
            }else {
                str=mid+1;
            }
        }
        return ans;
    }
};