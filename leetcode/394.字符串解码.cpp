#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int num = 0;
        stack<int> nums;
        stack<string> strs;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            else if(s[i] >= 'a' && s[i] <= 'z')
                res += s[i];
            else if(s[i] == '[') {
                nums.push(num);
                strs.push(res);
                num = 0;
                res = "";
            }
            else if(s[i] == ']') {
                int times = nums.top();  // 重复次数
                nums.pop();
                while(times--)
                    strs.top() += res;
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};