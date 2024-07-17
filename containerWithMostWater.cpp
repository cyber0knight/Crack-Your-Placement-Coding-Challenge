class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max = 0;
        int l=0;
        int r = height.size()-1;
        while(l<r)
        {
            int wid = r-l;
            int len = (height[l]<height[r]) ? height[l] : height[r];
            int area = len * wid;
            max = (area < max) ? max: area;
            if(height[l]<height[r]) l++;
            else r--;
        }
        return max;   
    }
};