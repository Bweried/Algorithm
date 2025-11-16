#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * method 1
 * 拓扑排序 判断是否有环
 */
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> g(numCourses);
//         vector<int> in_degree(numCourses, 0);
//         int cnt = 0;  // 记录拓扑排序访问的课程数

//         for(auto& v : prerequisites) {
//             int x = v[0], y = v[1];   // y -> x
//             g[y].push_back(x);
//             in_degree[x]++;
//         }

//         queue<int> q;

//         // 所有入度为 0 的点入队
//         for(int i = 0; i < numCourses; i++)
//             if(in_degree[i] == 0)
//                 q.push(i);
        
//         while(!q.empty()) {
//             int u = q.front();
//             q.pop();
//             cnt++;

//             for(int v : g[u]) {
//                 in_degree[v]--;
//                 if(in_degree[v] == 0)
//                     q.push(v);
//             }
//         }

//         return cnt == numCourses;
//     }
// };


/**
 * method 2
 * dfs
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    }
};