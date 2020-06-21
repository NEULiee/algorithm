#include <iostream>
#include <algorithm>
using namespace std;

int weight[501];
int value[501];
int dp[501][100001];

int knapsack(int, int);

int main() {
	int testCase, N, K;
	cin >> testCase;
	while (testCase--) {
		cin >> N >> K;
		cout << knapsack(N, K) << "\n";
	}
}

int knapsack(int N, int K) {
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - weight[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[N][K];
}