class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //this is the solution using hashing but not optimized 
        // set <vector<int>> uniqueQuadruplets;
        int n=nums.size();

        // for(int i=0;i<n;i++) {
        //     for(int j=i+1;j<n;j++) {
        //         unordered_set <long long> s;
                
        //         for(int k=j+1;k<n;k++) {
        //             long long four=(long long)target-nums[i]-nums[j]-nums[k];
        //             if(s.find(four)!=s.end()) {
        //                 vector<int>trip={nums[i],nums[j],nums[k],(int)four};
        //                 sort(trip.begin(),trip.end());
        //                 uniqueQuadruplets.insert(trip);
        //             }
        //             s.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(uniqueQuadruplets.begin(),uniqueQuadruplets.end());
        // return ans;

        //optimized solution is using two pointer 
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            if(i>0 && nums[i-1]==nums[i]) {continue;}
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) {continue;}

                int str=j+1;
                int end=n-1;
                while(str<end) {
                    long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[str]+(long long)nums[end];  //as can be large value of the sum so we store in the long long 
                    if(sum>target) {
                        end--;
                    }else if(sum<target) {
                        str++;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[str],nums[end]});
                        str++;
                        end--;
                        while(str<end && nums[str]==nums[str-1]) {str++;}
                        // while(str<end && nums[end]==nums[end+1]) {end--;}
                    }
                }
            }
        } 
        return ans;
    }
};