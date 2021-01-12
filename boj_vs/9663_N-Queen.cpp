#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int chess[16][16];
stack<pair<int, int>> queen;
stack<pair<int, int>> setQueen;

void setLine(int, int, int);
void delLine(int, int, int);
int nQueen(int);

int main() {
	int n;
	cin >> n;
	cout << nQueen(n);
}

void setLine(int x, int y, int n) {
	chess[x][y]++;
	for (int i = 1; i <= n; i++) {
		if (i != y) {
			chess[x][i]++;
		}
		if ((x + i) <= n) {
			chess[x + i][y]++;
			if ((y - i) >= 1)
				chess[x + i][y - i]++;
			if ((y + i) <= n)
				chess[x + i][y + i]++;
		}
	}
}

void delLine(int x, int y, int n) {
	chess[x][y]--;
	for (int i = 1; i <= n; i++) {
		if (i != y) {
			chess[x][i]--;
		}
		if ((x + i) <= n) {
			chess[x + i][y]--;
			if ((y - i) >= 1)
				chess[x + i][y - i]--;
			if ((y + i) <= n)
				chess[x + i][y + i]--;
		}
	}
}

int nQueen(int n) {
	if (n == 1) return 1;

	int result = 0;
	int line = 1;
	int x, y, noQueen;

	for (int i = 1; i <= n; i++) {
		queen.push(make_pair(line, i));
	}

	while (1) {
		if (setQueen.size() != 0 && queen.size() != 0 && queen.top().first <= setQueen.top().first) {
			while (1) {
				if (setQueen.size() == 0 || queen.top().first > setQueen.top().first) {
					break;
				}
				x = setQueen.top().first;
				y = setQueen.top().second;
				delLine(x, y, n);
				setQueen.pop();
			}
		}

		x = queen.top().first;
		y = queen.top().second;
		setLine(x, y, n);
		setQueen.push(make_pair(x, y));
		queen.pop();
		line = x + 1;

		noQueen = 0;
		for (int i = 1; i <= n; i++) {
			if (chess[line][i] == 0) {
				queen.push(make_pair(line, i));
				noQueen++;
			}
		}
		if (noQueen == 0) {

		}
		else {
			if (line == n) {
				while (queen.size() != 0 && queen.top().first == n) {
					result++;
					queen.pop();
				}
			}

		}

		if (queen.size() == 0) {
			break;
		}
	}
	return result;
}
