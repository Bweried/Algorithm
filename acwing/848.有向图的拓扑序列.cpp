#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100010;

int n, m;
vector<int> g[N];    // 邻接表
vector<int> in_degree(N);   // 入度表
int topo[N];        // 存放拓扑排序结果
int idx;            // 结果数组索引

bool topoSort() {
    queue<int> q;

    // 将入度为 0 的结点入队
    for(int i = 1; i <= n; i++) 
        if(in_degree[i] == 0)
            q.push(i);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo[idx++] = u;
        
        // 遍历所有出边
        for(int v : g[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
    }

    return idx == n;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;   // x -> y
        g[x].push_back(y);
        in_degree[y]++;
    }

    if(!topoSort()) puts("-1");
    else
        for(int i = 0; i < n; i++)
            cout << topo[i] << " ";
}