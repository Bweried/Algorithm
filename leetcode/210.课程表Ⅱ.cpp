#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// const int N = 2010;
// vector<int> g[N];
// int in_degree[N];
// vector<int> topo;

// class Solution {
// public:
//     bool topoSort(int n) {
//         queue<int> q;

//         for(int i = 0; i < n; i++) 
//             if(in_degree[i] == 0)
//                 q.push(i);

//         while(!q.empty()) {
//             int u = q.front();
//             q.pop();
//             topo.push_back(u);

//             // 将入度 - 1
//             for(auto& v : g[u]) {
//                 in_degree[v]--;
//                 if(in_degree[v] == 0)
//                     q.push(v);
//             }
//         }

//         return topo.size() == n;
//     }

//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         // 清空上一次的数据   leetcode多例测试会出错
//         topo.clear();
//         for(int i = 0; i < numCourses; i++) {
//             g[i].clear();
//             in_degree[i] = 0;
//         }
//         for(auto& v : prerequisites) {
//             int x = v[0], y = v[1];    // y -> x
//             g[y].push_back(x);
//             in_degree[x]++;
//         }

//         if(!topoSort(numCourses))
//             return vector<int>();
//         else
//             return topo;
//     }
// };


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in_degree(numCourses, 0);
        vector<int> topo;

        for(auto& v : prerequisites) {
            int x = v[0], y = v[1];
            g[y].push_back(x);
            in_degree[x]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(in_degree[i] == 0)
                q.push(i);

        while(!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(int v : g[u]) {
                if(--in_degree[v] == 0)
                    q.push(v);
            }
        }

        if(topo.size() == numCourses) return topo;
        return {};
    }
};


int main() {
    return 0;
}