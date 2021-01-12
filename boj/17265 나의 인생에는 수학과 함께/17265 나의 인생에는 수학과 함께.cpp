#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, _max = -1000000000, _min = 1000000000;
char map[6][6];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void dfs(int x, int y, int res, char op ) {
    for (int i=0; i<2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1<=nx&& nx<=N && 1<=ny && ny<=N) {
            if (map[nx][ny] == '+') {
                dfs(nx, ny, res, '+');
            }
            else if (map[nx][ny] == '-') {
                dfs(nx, ny, res, '-');
            }
            else if (map[nx][ny] == '*') {
                dfs(nx, ny, res, '*');
            }
            else {
                int cal = 0;
                if (op=='+') {
                    cal = res + (map[nx][ny] - '0');
                }
                else if (op=='-') {
                    cal = res - (map[nx][ny] - '0');
                }
                else if (op=='*') {
                    cal = res * (map[nx][ny] - '0');
                }
                
                if (nx==N && ny==N) {
                    _max = max(_max, cal);
                    _min = min(_min, cal);
                    return;
                }
                dfs(nx, ny, cal, op);            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }
    dfs(1, 1, map[1][1] - '0', 0);
    cout << _max << " " << _min << "\n";
}
