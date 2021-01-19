//
//  main.cpp
//  11725 트리의 부모 찾기 (트리)
//
//  Created by Ha Neul Iee on 2021/01/19.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nodes[100001];
bool isUsed[100001];
int parent[100001];
stack<int> node;
int N, a, b;

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i=0; i<N-1; i++) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    node.push(1);
    isUsed[1] = true;
    while(!node.empty()) {
        int p = node.top();
        node.pop();
        for (int i=0; i<nodes[p].size(); i++) {
            if (!isUsed[nodes[p][i]]) {
                parent[nodes[p][i]] = p;
                isUsed[nodes[p][i]] = true;
                node.push(nodes[p][i]);
            }
        }
    }
    for (int i=2; i<=N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}
