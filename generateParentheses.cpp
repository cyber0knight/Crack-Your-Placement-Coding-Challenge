
void add(int open,int close,int n,string s, vector<string> &v)
{
    if(open==n && close==n)
    {
        v.push_back(s);
    }
    if(open<n)
    {
        s = s+"(";
        add(open+1,close,n,s,v);
        s=s.substr(0,s.size()-1);
    }
    if(close<open)
    {
        s = s+")";
        add(open,close+1,n,s,v);
        s=s.substr(0,s.size()-1);
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> v;
        string s="";
        add(0,0,n,s,v);
        return v;
    }
};