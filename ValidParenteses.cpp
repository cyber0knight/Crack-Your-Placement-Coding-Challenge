class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++)   {
            char c = s[i];
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else    {
                if(!st.empty()) {
                    int t = st.top();
                    st.pop();
                    if((c == ')' && t == '(') || (c == ']' && t == '[') || (c == '}' && t == '{'))
                        continue;
                    else
                        return false;
                }
                else 
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};