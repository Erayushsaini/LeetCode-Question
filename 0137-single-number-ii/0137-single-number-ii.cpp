class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int val:nums) {
            map[val]++;
        }
        for(auto p:map) {
            if(p.second==1) {
                return p.first;
            }
        }
        return -1;
    }
};