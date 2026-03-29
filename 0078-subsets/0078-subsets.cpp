class Solution {
public:
    void getAllSubsets(vector<int> &nums,vector<int> &set,vector<vector<int>> &ans ,int i) {
        if(i==nums.size()) {
            //store subset
            ans.push_back(set);
            return;
        }

        set.push_back(nums[i]);
        getAllSubsets(nums,set,ans,i+1);
        set.pop_back();
        getAllSubsets(nums,set,ans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> set;
        int i=0;
        getAllSubsets(nums,set,ans,i);
        return ans;
    }
};