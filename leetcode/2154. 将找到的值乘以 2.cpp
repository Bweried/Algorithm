#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> se(nums.begin(), nums.end());

        while(se.find(original) != se.end())
            original *= 2;
        
        return original;
    }
};