class Solution {
public:
    int calculate(string s) {
        stack<char> oper;
        stack<int> nums;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] ==' '){
                continue;
            }
            int num=0;
            if(i<n && s[i]>='0' && s[i] <='9'){
                while(i<n && s[i]>='0' && s[i] <='9'){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                if(oper.empty()){
                    nums.push(num);
                }else if(oper.top() == '+'){
                    nums.push(num);
                    oper.pop();
                }else if(oper.top() == '-'){
                    nums.push(-num);
                    oper.pop();
                }else if(oper.top() == '*'){
                    int num1 = nums.top();
                    nums.pop();
                    oper.pop();
                    nums.push(num1*num);
                }else if(oper.top() == '/'){
                    int num1 = nums.top();
                    nums.pop();
                    oper.pop();
                    nums.push(num1/num);
                }
            }
            else{
                oper.push(s[i]);
            }
        }
        int ans =0;
        while(!nums.empty()){
            ans += nums.top();
            nums.pop();
        }
        return ans;
    }
};