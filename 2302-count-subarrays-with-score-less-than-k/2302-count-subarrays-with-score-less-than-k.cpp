class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        long long count=0;
        long long currWinSum=0;

        int i=0;
        int j=0;

        while(i<nums.size()) {
            while(j<nums.size() &&( currWinSum + nums[j])*(j-i+1)<k) {
                currWinSum+=nums[j];
                j++;
            }
            currWinSum-=nums[i];

            count+=j-i;

            i++;
            if(i<nums.size() && j<nums.size() && i==j && nums[j]>k) {
                i++;
                j++;
            }
        }
        return count;



        //this is o(n^2) approach gives the tle
        // long long count=0;
        // for(int i=0;i<nums.size();i++) {
        //     long long sum=0;
        //     for(int j=i;j<nums.size();j++) {
        //         long long length=(j-i+1);
        //         sum+=(long long)nums[j];

        //         if((sum*length)<k) {
        //             count++;
        //         }

        //     }
        // }
        // return count;
    }
};