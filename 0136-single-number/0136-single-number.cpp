class Solution {
public:
    int singleNumber(vector<int>& nums) {

        //time complexity is o(n) and s.c is o(1)
        int ans=0;
        for(int val:nums){
            ans^=val;
        }
        return ans;

        //other method is using hash map  in this o(n)time complexity and s.c is o(n)and sorting t.c(o(nlogn)) and space complexity is o(1)
        // unordered_map<int,int> map;

        // for(int i=0;i<nums.size();i++) {
        //     map[nums[i]]++;
        // }
        // for(auto p:map) {
        //     if(p.second==1) {
        //         return p.first;
        //     }
        // }
        // return -1;
    }        
};