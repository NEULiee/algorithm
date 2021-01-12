#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;

struct pos{
    int x;
    int y;
    int left;
    int right;
};

int N, M, L, R, sx, sy, cnt;
int map[1000][1000];
bool visit[1000][1000];
deque<pos> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(int argc, const char * argv[]) {
    string input;
    cin >> N >> M >> L >> R;
    for (int i=N-1; i>=0; i--) {
        cin >> input;
        for (int j=0; j<M; j++) {
            map[j][i] = input[j] - '0';
            if (map[j][i] == 2) {
                sx = j;
                sy = i;
            }
        }
    }
    
    pos p = {sx, sy, L, R};
    q.push_back(p);
    visit[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int left = q.front().left;
        int right = q.front().right;
        q.pop_front();
        
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<M && 0<=ny && ny<N && map[nx][ny] != 1 && !visit[nx][ny]) {
                if (i==3) {
                    if (left>0)    p = {nx, ny, left -1, right};
                    else    continue;
                }
                else if (i==1) {
                    if (right>0)    p = {nx, ny, left, right - 1};
                    else    continue;
                }
                else {
                    p = {nx, ny, left, right};
                }
                
                if (i==0 || i==2) {
                    q.push_front(p);
                }
                else if (i==1 || i==3) {
                    q.push_back(p);
                }
                
                visit[nx][ny] = true;
            }
        }
    }
    
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (visit[i][j]) {
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
