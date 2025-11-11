#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> v;
        int ans = 0;
        for(auto x : nums) {
            while(!v.empty() && v.back() > x)
                v.pop_back();
            if(x == 0)
                continue;
            if(v.empty() || v.back() < x){
                v.push_back(x);
                ans++;
            }
        }
        return ans;
    }
};