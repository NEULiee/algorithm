#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9
typedef pair<int, int> pii;

int V, M, a, b, c, J, S;
vector<pii> graph[101]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int dist[101]; // 최단 거리
int from[101]; // 직전 노드 저장

void dijkstra(int start) {
    priority_queue<pii> pq; // 거리, 노드
    
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while(!pq.empty()) {
        int now_dist = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        
        if (dist[now_node] < now_dist) {
            continue;
        }
        
        for (int i=0; i<graph[now_node].size(); i++) {
            int cost = now_dist + graph[now_node][i].second;
            
            if (cost < dist[graph[now_node][i].first]) {
                dist[graph[now_node][i].first] = cost;
                pq.push(make_pair(cost, graph[now_node][i].first));
                
                from[graph[now_node][i].first] = now_node;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> V >> M;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> J >> S;
    
    fill(dist, dist + 101, INF);
    
    dijkstra(J);
    
    cout << dist[J] << " " << dist[S] << "\n";
    for (int i=0; i<V; i++) {
        cout << from[i] << " ";
    }

    return 0;
}
