class Solution {
public:
    int subarraysDivByK(vector<int> &arr, int k) 
    {
        // for hasing the sum elements of array
        unordered_map<int,int> remMap;
        //intial value for for 0 is 1
        remMap[0] = 1;
        int count =0;
        long summ=0;
        
        for(int i=0;i<arr.size();i++)
        {
            // adding one by one element
            summ+=arr[i];
            // to find the remainder 
            int rem = (summ %k +k)%k;
            if(remMap.find(rem) !=remMap.end())
            {
                count += remMap[rem];
                remMap[rem] += 1;
            } else {
                remMap[rem] = 1;
            }
        }
        return count;
    }
};