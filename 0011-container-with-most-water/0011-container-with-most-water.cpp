class Solution {
public:
    int maxArea(vector<int>& height){
        // TLE CAME AS N <=10^5  as time complexity is o(n^2)
        //brute force approach
        // int mostWater=0;
        // for(int i=0;i<height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int minHeight=min(height[i],height[j]);
        //         mostWater=max(mostWater,minHeight*(j-i));
        //     }    
        // }
        // return mostWater;


        //two pointer approach 
        int lp=0,rp=height.size()-1;
        int mostWater=0;
        while(lp<rp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            mostWater=max(mostWater,w*ht);
            height[lp]<height[rp]?lp++:rp--;
        }
        return mostWater;
    }    
};