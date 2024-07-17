class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map[nums[i]]>1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};