#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, pair<int, int>> pipii;

int N, M, u, v, d, length = 0;
bool check;
int parent[1001];
char school[1001];
bool link[1001];
vector<pipii> road;

bool compare(pipii a, pipii b){
    return a.first < b.first;
}

int find(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void _union(int u, int v) {
    check = false;
    u = find(u);
    v = find(v);
    
    if (u==v){
        return;
    }
    check = true;
    link[u] = link[v] = true;
    parent[u] = v;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        cin >> school[i];
        parent[i] = i;
    }
    for (int i=0; i<M; i++){
        cin >> u >> v >> d;
        road.push_back(make_pair(d, make_pair(u, v)));
    }
    sort(road.begin(), road.end(), compare);
    
    for (int i=0; i<road.size(); i++) {
        u = road[i].second.first;
        v = road[i].second.second;
        d = road[i].first;
        if (school[u] != school[v]) {
            _union(u, v);
            if (check) {
                length += d;
            }
        }
    }
    
    for (int i=1; i<=N; i++) {
        if (!link[i]){
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << length << "\n";
    return 0;
}
