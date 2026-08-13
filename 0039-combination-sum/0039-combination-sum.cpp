class Solution {
public:


    void getComb(vector<vector<int>>& ans,vector<int>& result,vector<int>& candidates,int target,int idx,int currSum,int n) {
        
        if(currSum==target) {
            ans.push_back(result);
            return;
        }

        if(currSum>target) {
            return;
        }

        
        for(int i=idx;i<n;i++) {
            currSum+=candidates[i];

            result.push_back(candidates[i]);

            if(currSum<=target) {
                getComb(ans,result,candidates,target,i,currSum,n);
            }
            result.pop_back();
            currSum-=candidates[i];
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> result;
        getComb(ans,result,candidates,target,0,0,n);
        return ans;
    }
};