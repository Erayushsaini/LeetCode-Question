class Solution {
public:

    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long ans = 0;
        
        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            
            // shrink window until valid
            while (sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            
            // count valid subarrays ending at j
            ans += (j - i + 1);
        }
        
        return ans;
    }
};
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
