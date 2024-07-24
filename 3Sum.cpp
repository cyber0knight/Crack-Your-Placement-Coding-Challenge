class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(int i=0;i<n;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int left= i+1;
            int right = n-1;
            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    v.push_back({nums[i],nums[left],nums[right]});
                    right--;
                    while(right!=1 && nums[right]==nums[right+1]) right--;
                    left++;
                    while(left!=n-1 && nums[left]==nums[left-1]) left++;
                }else if(nums[i]+nums[left]+nums[right]>0)
                {
                    right--;
                    while(right!=1 && nums[right]==nums[right+1]) right--;
                }else{
                    left++;
                    while(left!=n-1 && nums[left]==nums[left-1]) left++;
                }
            }
        }
        return v;
    }
};