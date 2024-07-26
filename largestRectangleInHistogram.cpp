class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        heights.push_back(0);
        int n = heights.size();
        int area=0;
        vector<int> st = {-1};
        for(int i=0;i<n;i++){
            while(st.size()>1 && heights[st.back()]>=heights[i])
            {
                const int m = st.back();
                st.pop_back();
                const int w = i - st.back()-1;
                const int ar = heights[m]*w;
                area = max(area, ar);
            }
            st.push_back(i);
        }
        return area;
    }
};