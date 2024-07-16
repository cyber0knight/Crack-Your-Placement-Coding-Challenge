class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        int fir, sec, flag = 0;
        for(int i=0;i<n;i++){
            int val = nums[i];
            int needed = target- val;
            if(map.find(needed) != map.end()){
                fir = map[target - val];
                sec = i;
                flag = 1;
                break;
            }else{
                map[val] = i;
            }
        }
        return {fir, sec};
    }
};
