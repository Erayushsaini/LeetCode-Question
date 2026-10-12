class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();

        int rot=k%n;

        if(n==1) {
            return;
        }
        if(rot==0) {
            return;
        }

        reverse(nums.begin(),nums.begin()+(n-rot));
        reverse(nums.begin()+(n-rot),nums.end());

        reverse(nums.begin(),nums.end());
    }
};