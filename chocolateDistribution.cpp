#include<bits/stdc++.h>
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        int ans = INT_MAX;
        sort(a.begin(), a.end());
        int j=0;
        for(int i=m-1;i<n;i++){
            int val = a[i] - a[j++];
            ans = min(ans, val );
        }
        return ans;
    }   
};
