// Problem Link: https://practice.geeksforgeeks.org/problems/prefix-to-postfix-conversion/0

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        int n = pre_exp.length();
        for(int i = n-1; i>=0; i--)
        {
            if((pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9'))
            {
                string temp1 = "";
                temp1 = pre_exp[i];
                st.push(temp1);
            }
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string temp = op1+op2+pre_exp[i];
                st.push(temp);
            }
        } 
        return st.top();  
    }
};