#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>v1(m, 0), v2(n, 0);   // 存储哪些行、列有0
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0){
                    v1[i] = 1;
                    v2[j] = 1;
                }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v1[i] == 1 || v2[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};