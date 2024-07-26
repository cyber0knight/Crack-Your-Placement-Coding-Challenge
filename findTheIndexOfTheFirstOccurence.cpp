class Solution {

    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

public:
    int strStr(string haystack, string needle) {
        haystack = needle+haystack;
        vector<int> z = z_function(haystack);
        for(auto z1:z) cout<<z1<<" ";
        int n = z.size();
        for(int i=needle.size();i<n;i++){
            if(z[i]>=needle.size()){
                return i-needle.size();
            }
        }

        return -1;
    }
};