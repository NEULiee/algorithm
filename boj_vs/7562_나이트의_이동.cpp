#include <iostream>
#include <queue>
using namespace std;

int dist[300][300];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void game(int, int, int, int, int);

int main() {
	int testCase, l, startX, startY, finishX, finishY;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> l >> startX >> startY >> finishX >> finishY;
		game(l, startX, startY, finishX, finishY);
	}
}

void game(int l, int startX, int startY, int finishX, int finishY) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			dist[i][j] = 0;
		}
	}
	queue<pair<int, pair<int, int>>> q;
	// distance, x, y
	int nextX, nextY;
	dist[startX][startY] = 0;
	q.push(make_pair(0, make_pair(startX, startY)));
	while (!q.empty()) {
		int td = q.front().first;
		int tx = q.front().second.first;
		int ty = q.front().second.second;
		q.pop();
		if (tx == finishX && ty == finishY) {
			cout << td << "\n";
			break;
		}
		for (int i = 0; i < 8; i++) {
			nextX = tx + dx[i];
			nextY = ty + dy[i];
			if (nextY >= 0 && nextX >= 0 && nextX < l && nextY < l && dist[nextX][nextY] == 0) {
				dist[nextX][nextY] = dist[tx][ty] + 1;
				q.push(make_pair(dist[nextX][nextY],make_pair(nextX, nextY)));
			}
		}
	}
}