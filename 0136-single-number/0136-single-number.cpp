class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int i=0;i<nums.size();i++) {
            map[nums[i]]++;
        }
        int i=0;
        // while(i<nums.size()) {
        //     if(map.count(nums[i])==1) {
        //         return nums[i];
        //     }else {
        //         i++;
        //     }
        // }
        for(auto p:map) {
            if(p.second==1) {
                return p.first;
            }
        }
        return -1;
    }
};