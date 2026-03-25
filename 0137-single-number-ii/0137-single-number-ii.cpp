class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;){  //or can do nums.size() so in the if condition change is 
            if(nums[i]==nums[i+1] && nums[i]==nums[i+1]) { //i+1<nums.size() && i+2<nums.size() && then other written line 
                i=i+3;
            }
            else{
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};