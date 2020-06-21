#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 16;

int t, r, c;
int map[MAX][MAX];
bool finish;

int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { -1,0,-1,-1,1,0,1,1 };
const char res[] = { 'W', 'B' };

bool over(int r, int c) {
	if (r < 1 || c < 1 || r > 15 || c > 15) return true;
	else return false;
}

int move(int r, int c, int dir, int color) {
	int cnt = 0;
	while (1) {
		int nr = r + (cnt + 1) * dr[dir];
		int nc = c + (cnt + 1) * dc[dir];

		if (over(nr, nc)) return cnt;
		else {
			if (map[nr][nc] == color) cnt++;
			else return cnt;
		}
	}
	return cnt;
}

void func(int r, int c, int color) {
	for (int i = 0; i < 4; i++) {
		int cnt = 1;
		cnt += move(r, c, i, color);
		cnt += move(r, c, 4 + i, color);

		if (cnt == 5) finish = true;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	// cin.tie(0);

	cin >> t;
	while (t--) {
		memset(map, -1, sizeof(map));
		finish = false;
		int cnt = 230;
		for (int i = 0; i < 225; i++) {
			cin >> r >> c;
			map[r][c] = i % 2;

			if (!finish) func(r, c, i % 2);
			else cnt = min(i, cnt);
		}
		cout << cnt << " " << res[cnt % 2] << '\n';
	}



	return 0;
}