//
//  main.cpp
//  1167 트리의 지름 (트리)
//
//  Created by Ha Neul Iee on 2021/01/19.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define initialize(x, y) memset(x, y, sizeof(x));
typedef pair<int, int> pii;

int V, v, a, b;
vector<pii> edges[100001];
bool visited[100001];

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
    cin >> V;
    for (int i=1; i<=V; i++) {
        cin >> v;
        while(1) {
            cin >> a;
            if (a == -1) {
                break;
            }
            cin >> b;
            edges[v].push_back(make_pair(a, b));
        }
    }
    dfs(1, 0);
    cost = 0;
    initialize(visited, false);
    dfs(root, 0);
    cout << cost << "\n";
    return 0;
}
