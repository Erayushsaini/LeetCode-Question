class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {


        //optimized approach using hashing and prefix sum

        vector<int> ps;

        int sum=0;
        int count=0;

        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            ps.push_back(sum);
        }
        unordered_map<int,int> map;
        map.emplace(0,1);
        for(int i=0;i<nums.size();i++) {
            int PS=ps[i]-k;

            if(map.find(PS)!=map.end()) {
                count=count+map[PS];

            }
            map[ps[i]]++;
        }
        return count;
       
       //in this approach T.c is o(n*2) so brute force 
        // int n=nums.size();
        // int count=0;
        // for(int i=0; i<n ;i++) {
        //     int sum=0;
        //     for(int j=i ;j<n ;j++) {
        //         sum+=nums[j];
        //         if(sum==k) {
        //             count++;
        //         }
        //     }
        // }
        // return count;
    
    }
};