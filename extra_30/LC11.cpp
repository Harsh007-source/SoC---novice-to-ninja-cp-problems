class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lp = 0,rp = n-1;
        
        int max_area = 0;
        
        while(lp<rp){
            int w = rp-lp;
            int h = min(height[lp], height[rp]);
            int curr_area = w * h;
            max_area = max(max_area, curr_area);
            
            height[lp]<height[rp] ? lp++ : rp--;

        } 
        return max_area;
    }
};
