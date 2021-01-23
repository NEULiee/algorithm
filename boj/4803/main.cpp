//
//  main.cpp
//  4803 트리 (트리)
//
//  Created by Ha Neul Iee on 2021/01/21.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define initialize(x, y) memset(x, y, sizeof(x));
typedef pair<int, int> pii;

int n, m, u, v, treeCount;
vector<int> edges[501];
bool visited[501];
bool visited2[501];

int countVertices(int v) {
    int cnt = 1;
    visited[v] = true;
    for (int i=0; i<edges[v].size(); i++) {
        int nextVertex = edges[v][i];
        if (!visited[nextVertex]) {
            cnt += countVertices(nextVertex);
        }
    }
    return cnt;
}

int countEdges (int v) {
    int cnt = (int)edges[v].size();
    visited2[v] = true;
    for (int i=0; i<edges[v].size(); i++) {
        int nextVertex = edges[v][i];
        if (!visited2[nextVertex]) {
            cnt += countEdges(nextVertex);
        }
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    int testCase = 1;
    while (1) {
        cin >> n >> m;
        for (int i=0; i<=500; i++) {
            edges[i].clear();
        }
        if (n==0 && m==0) {
            return 0;
        }
        for (int i=0; i<m; i++) {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        treeCount = 0;
        initialize(visited, false);
        initialize(visited2, false);
        for (int i=1; i<=n; i++) {
            if (!visited[i]) {
                int cntVertex = countVertices(i);
                int cntEdge = countEdges(i);
                if (cntVertex - 1 == cntEdge / 2) {
                    treeCount++;
                }
            }
        }
        if (treeCount == 0) {
            cout << "Case " << testCase << ": No trees.\n";
        }
        else if (treeCount == 1) {
            cout << "Case " << testCase << ": There is one tree.\n";
        }
        else {
            cout << "Case " << testCase << ": A forest of " << treeCount << " trees.\n";
        }
        testCase++;
    }
}

