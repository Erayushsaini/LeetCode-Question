class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // brute force approach
        // for(int val:nums){
        //     int freq = 0;
        //     for(int el:nums){
        //         if(val==el){
        //             freq++;
        //         }
        //     }
        //     if(freq>(nums.size()/2)){
        //         return val;
        //     }
        // }
        // return -1;




    //using map 

        // // better optimised approach 
        // int n=nums.size();

        // //sort function
        // sort(nums.begin(),nums.end());

        // //frequenncy

        // int freq = 1;
        // int ans=nums[0];
        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1]){
        //         freq++;
        //     }else{
        //         freq=1;
        //         ans=nums[i];
        //     }
        //     if(freq>(n/2)){
        //         return ans;
        //     }
        // }
        // return ans;


//moore's voting algorithms 

    int n=nums.size();
    int count=0;
    int major=nums[0];
    for(int i=0;i<n;i++) {
        if(count==0) {
            major=nums[i];
        }
        if(nums[i]==major) {
            count++;
        }else {
            count--;
        }
    }
    return major;
    }
};
