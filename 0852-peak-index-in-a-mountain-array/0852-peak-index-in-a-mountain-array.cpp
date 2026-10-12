class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr){

        
        //brute force approach is linear seach that is moving in array checking condition of the peak elements or if find only value of the peak element then maximum is used here index is also needed


        //this binary search approach 
        int str=1;
        int end=arr.size()-2;//this optimization for removing unnesseary checks 


        while(str<=end){
            int mid=str+(end-str)/2;
            
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
                return mid;
            }
            if(arr[mid-1]<arr[mid]){
                str=mid+1;
            }
            else{
                end=mid-1;
            }
            

        } 
        return -1;   
    }
};