class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int val = INT_MAX;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<val){
                val = nums[i];
                continue;
            }
            ans = max(ans, nums[i] - val);
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};
