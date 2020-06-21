#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
	int weight;
	int value;
	int vw;
};

item items[501];

int knapsackFraction(int, int);
bool compare(const item&, const item&);

int main() {
	int testCase, N, K;
	cin >> testCase;
	while (testCase--) {
		cin >> N >> K;
		cout << knapsackFraction(N, K) << "\n";
	}
}

bool compare(const item& x, const item& y) {
	if (x.vw == y.vw) {
		x.weight < y.weight;
	}
	return x.vw > y.vw;
}

int knapsackFraction(int N, int K) {
	int capacity = K, idx = 1, answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> items[i].weight;
	}
	for (int i = 1; i <= N; i++) {
		cin >> items[i].value;
		items[i].vw = items[i].value / items[i].weight;
	}
	sort(items + 1, items + N + 1, compare);

	while (idx <= N && capacity - items[idx].weight >= 0) {
		capacity -= items[idx].weight;
		answer += items[idx].value;
		idx++;
	}
	answer += items[idx].vw * capacity;
	return answer;
}

