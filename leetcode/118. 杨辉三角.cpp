#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};

        // 从第二行开始遍历
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> cur(i + 1, 1);
            for(int j = 1; j < i; j++) {
                cur[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(cur);
        }
        return ans;
    }
};