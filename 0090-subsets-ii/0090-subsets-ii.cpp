class Solution {
public:

    void getAllSubset(vector<vector<int>> &allSubset,vector<int> &nums,vector<int> &ans,int i) {
        if(i==nums.size()) {
            allSubset.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getAllSubset(allSubset,nums,ans,i+1);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) {
            idx++;
        }
        getAllSubset(allSubset,nums,ans,idx);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allSubset;
        vector<int> ans;
        int i=0;
        getAllSubset(allSubset,nums,ans,i);

        return allSubset;

    }
};