class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set <vector<int>> uniqueQuadruplets;
        int n=nums.size();

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                unordered_set <long long> s;
                
                for(int k=j+1;k<n;k++) {
                    long long four=(long long)target-nums[i]-nums[j]-nums[k];
                    if(s.find(four)!=s.end()) {
                        vector<int>trip={nums[i],nums[j],nums[k],(int)four};
                        sort(trip.begin(),trip.end());
                        uniqueQuadruplets.insert(trip);
                    }
                    s.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(uniqueQuadruplets.begin(),uniqueQuadruplets.end());
        return ans;
    }
};