// union - Find
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edge;
int parent[1001];

int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = findParent(parent[x]);
	}
}

void union_F(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		parent[y] = x;
	}
}

bool sameParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int a, b, c, output = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(edge.begin(), edge.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		if (sameParent(edge[i].second.first, edge[i].second.second) == false) {
			union_F(edge[i].second.first, edge[i].second.second);
			output += edge[i].first;
		}
	}

	cout << output;

}