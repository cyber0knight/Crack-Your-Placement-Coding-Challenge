class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        map<int,int> m;
        int r, w, b;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        r = m[0];
        w = m[1];
        b = m[2];
        for(int i=0;i<nums.size();i++)
        {
            if(r!=0)
            {
                nums[i]=0;
                r--;
            }
            else if(w!=0)
            {
                nums[i]=1;
                w--;
            }
            else if(b!=0)
            {
                nums[i]=2;
                b--;
            }
        }
    }
};