//
//  main.cpp
//  1967 트리의 지름 (트리)
//
//  Created by Ha Neul Iee on 2021/01/20.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define initialize(x, y) memset(x, y, sizeof(x));
typedef pair<int, int> pii;

int n, u, v, w;
vector<pii> edges[10001];
bool visited[10001];

int cost, root;

void dfs(int num, int currentCost) {
    if (visited[num]) {
        return;
    }
    if (cost < currentCost) {
        cost = currentCost;
        root = num;
    }
    visited[num] = true;
    for (int i=0; i<edges[num].size(); i++) {
        dfs(edges[num][i].first, currentCost + edges[num][i].second);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
    dfs(1, 0);
    cost = 0;
    initialize(visited, false);
    dfs(root, 0);
    cout << cost << "\n";
    return 0;
}
