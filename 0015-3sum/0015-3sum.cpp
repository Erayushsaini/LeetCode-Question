class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //optimised approach using two pointer 

        int n=nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++) {
            if(i-1>=0 && nums[i]==nums[i-1]) {
                continue;
            }
            int tar=-nums[i];
            int st=i+1;
            int end=n-1;

            while(st<end) {
                int sum=nums[st]+nums[end];

                if(sum == tar) {
                    ans.push_back({nums[i],nums[st],nums[end]});
                    st++;
                    end--;

                    while(st<end && nums[st]==nums[st-1]) {st++;}
                    while(st<end && nums[end]==nums[end+1]) {end--;}
                }else if(sum>tar) {
                    end--;
                }else {
                    st++;
                }
            }

        }
        //approach using hashing but give TLE


        // set <vector<int>> s;

        // int n=nums.size();

        // for(int i=0;i<n;i++) {
        //     int tar=-nums[i];
            
        //     unordered_set<int> checker;
        //     for(int j=i+1;j<n;j++) {
        //         int three=tar-nums[j];

        //         if(checker.find(three)!=checker.end()) {
        //             vector<int> trip={nums[i],nums[j],three};
        //             sort(trip.begin(),trip.end());
        //             s.insert(trip);             
        //         }
        //         checker.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(s.begin(),s.end());
        
        return ans;
    }
};