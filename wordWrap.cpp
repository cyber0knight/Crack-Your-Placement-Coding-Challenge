
class Solution {
    vector<int> dp;
    int find(vector<int> &nums, int k, int ind){
        int n = nums.size();
        if(ind == n){
            return 0;
        }
        int len=0;
        int ans=INT_MAX;
        if (dp[ind] != -1) {
            return dp[ind];
        }
        for(int i=ind;i<n;i++){
            len += nums[i];

            if (len <= k) {
                int cost;
                if (i == n - 1) {
                    cost = 0;  // No extra cost for the last line
                } else {
                    cost = (k - len) * (k - len);
                }

                ans = min(ans, cost + find(nums, k, i + 1));
                len++;  
            } else {
                break;
            }
        }
        return dp[ind] =  ans;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        dp.assign(nums.size(), -1);
        return find(nums, k, 0);
    } 
};