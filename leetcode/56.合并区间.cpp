#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按左端点排序
        sort(intervals.begin(), intervals.end(), cmp);

        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            // 如果当前区间与上一个区间重叠
            if(intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }


    static bool cmp(const vector<int>& arr1, const vector<int>& arr2) {
        return arr1[0] < arr2[0];
    }
};

int main() {
    return 0;
}