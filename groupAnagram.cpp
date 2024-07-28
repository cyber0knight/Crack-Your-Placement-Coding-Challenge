class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> map;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(map.find(s) != map.end()){
                map[s].push_back(i);
            }
            else{
                map[s].push_back(i);
            }
        }
        vector<vector<string>> v;
        for(auto m:map){
            vector<string> s;
            for(auto i: m.second){
                s.push_back(strs[i]);
            }
            v.push_back(s);
        }
        return v;
    }
};