class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //solution using the bit manupulation 
        int ans=0;
        for(int i=0;i<32;i++) {
            int count=0;
            for(int j=0;j<nums.size();j++) {
                if(((nums[j]>>i)&1)==1) {
                    count++;
                }
            }
            if(count%3!=0) {
                ans=ans|(1<<i);
            }
        }
        return ans;





        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;){  //or can do nums.size() so in the if condition change is 
        //     if(nums[i]==nums[i+1] && nums[i]==nums[i+1]) { //i+1<nums.size() && i+2<nums.size() && then other written line 
        //         i=i+3;
        //     }
        //     else{
        //         return nums[i];
        //     }
        // }
        // return nums[nums.size()-1]; //this is the edge case 


        //other solution by  using map but t.c is o(n) and space complexity is o(n)
        // unordered_map<int,int> map;

        // for(int val:nums) {
        //     map[val]++;
        // }
        // for(auto p:map) {
        //     if(p.second==1) {
        //         return p.first;
        //     }
        // }
        // return -1;

    }
};