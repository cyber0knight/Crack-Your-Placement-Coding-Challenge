class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ct = 0;
        vector<int> v(n);
        map<int, int> map;
        v[0] = nums[0];
        for(int i=1;i<n;i++){
            v[i] = nums[i] + v[i-1];
        }
        for(int i=0;i<n;i++){
            if(v[i] == k){
                ct++;
            }
            if(map.find(v[i] - k) != map.end()){
                ct += map[v[i]-k];
            }
            map[v[i]]++;
        }
        return ct;
    }
};