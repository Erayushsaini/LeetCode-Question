class Solution {
public:


    void getans(vector<vector<int>>& result,vector<int>& ans , vector<bool>& used,vector<int>& nums) {
        if(ans.size()==nums.size()) {
            result.push_back(ans);
            return;
        }

        for(int i=0 ;i<nums.size();i++) {
            if(used[i]) {
                continue;
            }

            used[i]=true;
            ans.push_back(nums[i]);

            getans(result,ans,used,nums);

            ans.pop_back();

            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        vector<bool> used(nums.size(),false);

        getans(result,ans,used,nums);

        return result;

    }
};