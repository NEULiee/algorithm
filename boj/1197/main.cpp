//
//  main.cpp
//  1197 최소 스패닝 트리 (MST)
//
//  Created by Ha Neul Iee on 2021/02/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppiii;

int V, E, A, B, C, sum;
int parent[10001];
vector<ppiii> edges;

int findParent(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findParent(parent[v]);
}

bool compare(ppiii A, ppiii B) {
    return A.second < B.second;
}

int main(int argc, const char * argv[]) {
    cin >> V >> E;
    for (int i=1; i<=V; i++) {
        parent[i] = i;
    }
    for (int i=0; i<E; i++) {
        cin >> A >> B >> C;
        edges.push_back(make_pair(make_pair(A, B), C));
    }
    sort(edges.begin(), edges.end(), compare);
    for (int i=0; i<(int)edges.size(); i++) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        long w = edges[i].second;
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        // union
        if (parent_u != parent_v) {
            parent[parent_u] = parent_v;
            sum += w;
        }
    }
    cout << sum << "\n";
    return 0;
}
