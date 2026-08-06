class Solution {
public:

    void getans(vector<vector<int>>& result ,int idx,vector<int>& nums) {
        if(idx==nums.size()) {
            result.push_back(nums);
        }

        for(int i=idx ; i<nums.size();i++) {

            bool isSame=false;

            for(int j=idx;j<i;j++) {
                if(nums[j]==nums[i]) {
                    isSame=true;
                    break;
                }
            }
            if(isSame) {
                continue;
            }
            swap(nums[i],nums[idx]);
            getans(result,idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        getans(result ,0,nums);
        
        return result;
    }
};