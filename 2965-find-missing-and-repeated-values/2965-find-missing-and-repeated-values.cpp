class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();  

        unordered_set<int> s;
        vector<int> ans; 

        int actualSum=0 ,expSum=0;
        int a,b;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {

                actualSum +=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);//here we not use break as we have to traverse  whole grid as we know there is only one a in the whole grid 
                }
                s.insert(grid[i][j]);
            }
        }
        expSum= (n*n) * (n*n +1)/2;

        b=expSum+a-actualSum;
        ans.push_back(b);
        return ans ;
    }
};