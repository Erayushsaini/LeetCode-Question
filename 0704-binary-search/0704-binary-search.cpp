class Solution {
public:
    int bs(vector<int>& arr, int tar,int st,int end) {//this is our helper function as in our question sometime complete  parameter are not given which is needed to do recursion ,so we make this function having those parameter   
        if(st<=end) {
            int mid=st+(end-st)/2;

            if(arr[mid]==tar) {
                return mid;
            }else if(tar>arr[mid]) {
                return bs(arr,tar,mid+1,end);
            }else {
                return bs(arr,tar,st,mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int tar) {
        int st=0;
        int end=arr.size()-1;
        return bs(arr,tar,st,end);
    }
};