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
        map.emplace(0,1);//or instead we can do that we amke a if condition in the for loop that 
        for(int i=0;i<nums.size();i++) {
            //if(ps[j]==k) {count++;}
            int PS=ps[i]-k;

            if(map.find(PS)!=map.end()) {
                count=count+map[PS]; //also can write count+=map[PS];

            }
            //or also can intiate a quantity with 0
            //if(map.find(PS)==map.end()) {map[PS]=0;}

            map[ps[i]]++;//as here if a quantity not exist in the map here when add and ++ this will intiate first with 0 (default value of the int) and ++ in 0 is 1  
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