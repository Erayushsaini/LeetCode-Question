class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();

        int str=0;

        int end=n-1;
        int ans =INT_MAX;

        while(str<=end) {
            int mid=str+(end-str)/2;

            //mid in the rotated array
            if(arr[mid]>=arr[str] && arr[str]>arr[end]) {
                str=mid+1;
            }else {//mid in the normal array
                ans=min(ans,arr[mid]);
                end=mid-1;
            }
        }
        return ans;
    }
};