class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        string prefix = strs[0];
        int count = strs.size();
        
        for (int i = 1; i < count; i++) {
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix.empty()) break;
        }
        
        return prefix;
    }
    
    string commonPrefix(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int n = min(n1, n2);
        int i;
        for (i = 0; i < n; i++) {
            if (str1[i] != str2[i]) break;
        }
        return str1.substr(0, i);
    }
};