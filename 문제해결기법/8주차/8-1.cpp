#include <iostream>
using namespace std;

int score[101];
int slot[102];

int onlineSorting(int, int);

int main() {
	int testCase, M, N;
	cin >> testCase;
	while (testCase--) {
		cin >> M >> N;
		cout << onlineSorting(M, N) << "\n";
	}
}

int onlineSorting(int M, int N) {
	for (int i = 0; i < 102; i++) {
		slot[i] = 0;
	}
	int s, value, idx, sum = 0, combo = 1;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		score[i] = s;
	}
	for (int i = 0; i < M; i++) {
		cin >> value >> idx;
		slot[idx] = value;
	}

	for (int i = 2; i <= M + 1; i++) {
		if (slot[i - 1] < slot[i]) {
			combo++;
		}
		else {
			sum += score[combo];
			combo = 1;
		}
	}
	return sum;
}