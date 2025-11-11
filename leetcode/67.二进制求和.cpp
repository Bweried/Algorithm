#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int lenA = a.size(), lenB = b.size();

        int carry = 0;  // 进位
        string ans = "";
        for(int i = 0; i < max(lenA, lenB); i++) {
            if(i < lenA) carry += a[i] - '0';
            if(i < lenB) carry += b[i] - '0';

            if(carry == 0) ans += "0";
            else if(carry == 1) {
                ans += "1";
                carry = 0;
            }
            else if(carry == 2) {
                ans += "0";
                carry = 1;
            }
            else if(carry == 3) {
                ans += "1";
                carry = 1;
            }
        }
        if(carry) ans += "1";

        reverse(ans.begin(), ans.end());

        // 计算前导零个数
        int cnt = 0;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '0')
                cnt++;
            else
                break;
        }

        if(cnt == 1 && ans.size() == 1) return ans;
        else
            return ans.substr(cnt);
    }
};