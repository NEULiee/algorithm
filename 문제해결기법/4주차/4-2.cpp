// correct

#include <iostream>
#include <queue>
using namespace std;

int dist[500][500];
int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

void move();

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		move();
	}
}

void move() {
	int L, startX, startY, finishX, finishY;
	cin >> L;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			dist[i][j] = 0;
		}
	}
	cin >> startX >> startY >> finishX >> finishY;

	queue<pair<int, pair<int, int>>> q;
	// distance, x, y
	int nextX, nextY;
	q.push(make_pair(0, make_pair(startX, startY)));
	while (!q.empty()) {
		int td = q.front().first;
		int tx = q.front().second.first;
		int ty = q.front().second.second;
		q.pop();
		if (tx == finishX && ty == finishY) {
			cout << td << "\n";
			return;
		}
		for (int i = 0; i < 8; i++) {
			nextX = tx + dx[i];
			nextY = ty + dy[i];
			if (nextX >= 0 && nextY >= 0 && nextX < L && nextY < L && dist[nextX][nextY] == 0) {
				dist[nextX][nextY] = dist[tx][ty] + 1;
				q.push(make_pair(dist[nextX][nextY], make_pair(nextX, nextY)));
			}
		}
	}
}