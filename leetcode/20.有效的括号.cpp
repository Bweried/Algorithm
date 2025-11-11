#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        if(n % 2 == 1)
            return false;
        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else if(c == ')'){
                if(st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if(ch != '(')
                    return false;
            }
            else if (c == ']')
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if (ch != '[')
                    return false;
            }
            else if (c == '}')
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if (ch != '{')
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};