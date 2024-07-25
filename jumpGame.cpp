class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxVal = nums[0];
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        for(int i=1;i<n-1;i++){
            maxVal--;
            maxVal = max(maxVal, nums[i]);
            if(maxVal == 0) return false;
        }
        return true;
    }
};