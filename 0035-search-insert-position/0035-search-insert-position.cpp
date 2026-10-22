class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int str=0;
        int end=arr.size()-1;


        while(str<=end) {
            int mid=str+(end-str)/2;

            if(arr[mid]==target) {
                return mid;
            }else if(arr[mid]>target) {
                end=mid-1;
            }else {
                str=mid+1;
            }
        }
        return str;
    }
};