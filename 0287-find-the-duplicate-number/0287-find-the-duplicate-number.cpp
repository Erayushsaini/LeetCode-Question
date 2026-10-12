class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //one way is to find by the using the sets or maps  but not constant extra space 

        //one way is by the sorting but in this the array is modified

        //way left is the slow and fase pointer 
        

        int slow=nums[0];

        int fast=nums[0];


        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(fast!=slow);

        slow=nums[0];

        while(slow!=fast) {
            slow=nums[slow];
            fast=nums[fast];

        }

        return slow;
    }
};