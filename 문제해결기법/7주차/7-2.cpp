#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[1001];
int package[1001];
int parent[1001];
vector<pair<int, pair<int, int>>> edge;

int findRoot(int);
void updateRoot(int, int);
int shopping();

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cout << shopping() << "\n";
	}
	return 0;
}

int shopping() {
	edge.clear();
	int N;
	cin >> N;
	int product_cost = 0, sub_cost = 0;
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i] >> package[i];
		product_cost += cost[i];
		// fees edge
		edge.push_back(make_pair(cost[i], make_pair(0, i)));
		if (i > 1) {
			// package fee edge
			edge.push_back(make_pair(package[i], make_pair(i - 1, i)));
		}
	}
	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		int _cost = edge[i].first;
		
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if (root_u != root_v) {
			updateRoot(root_u, root_v);
			sub_cost += _cost;
		}
	}
	return product_cost + sub_cost;
}

int findRoot(int vertex) {
	if (parent[vertex] == vertex) {
		return vertex;
	}
	else {
		return findRoot(parent[vertex]);
	}
}

void updateRoot(int root_u, int root_v) {
	parent[root_u] = parent[root_v];
}