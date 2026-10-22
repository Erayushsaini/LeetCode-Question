class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    //brute force appproach 
        // bool flag=false;
        // vector<int> ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++) {
        //     if(flag) {
        //         if((i<n-1 && nums[i+1]!=nums[i]) || i==n-1) {
        //             ans.push_back(i);
        //             return ans;
        //         }
        //     }else {
        //         if(nums[i]==target) {
        //             flag=true;
        //             ans.push_back(i);
        //         }
        //     }
        // }
        // ans.push_back(-1);
        // ans.push_back(-1);
        // return ans;
        



        int first=-1;
        int last=-1;

        vector<int> ans;

        int str=0;
        int end=nums.size()-1;

        while(str<=end) {
            int mid=str+(end-str)/2;

            if(nums[mid]==target) {
                if((mid>str && nums[mid-1]!=target) || (mid==str && nums[mid]==target)) {
                    first=mid;
                    break;
                }else {
                    end=mid-1;
                }
            }else if(nums[mid]>target) {
                end=mid-1;
            }else {
                str=mid+1;
            }
        }
        if(first!=-1) {
            str=first;
            end=nums.size()-1;

            while(str<=end) {
                int mid=str+(end-str)/2;

                if(nums[mid]==target) {
                    if((mid<end && nums[mid+1]!=target) || (mid==end && nums[mid]==target)) {
                        last=mid;
                        break;
                    }else {
                        str=mid+1;
                    }
                }else {
                    end=mid-1;
                }
            }
        }
        
        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};