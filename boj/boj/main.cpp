#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <deque>
using namespace std;

typedef long long int lld;
int n, m, l, r;
bool visited[1001][1001];
int ma[1001][1001];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

struct Land {
   int y = 0; int x = 0; int left = 0; int right = 0;
};

bool isInside(int y, int x) {
   if (y >= 0 && y < n && x >= 0 && x < m) {
      return true;
   }return false;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   cin >> n >> m >> l >> r;
   deque<Land> q;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         scanf("%1d", &ma[i][j]);
         if (ma[i][j] == 2) {
            Land start = { i,j,l,r };
            visited[i][j] = true;
            q.push_front(start);
         }
      }
   }
   int ans = 0;
   while (!q.empty()) {
      Land curr = q.front();
      q.pop_front();
      for (int i = 0; i < 4; i++) {
         Land next = curr;
         next.y += dy[i];
         next.x += dx[i];
         if (isInside(next.y, next.x) && !visited[next.y][next.x] && ma[next.y][next.x] != 1) {
            if (i == 0 || i == 1) {
               visited[next.y][next.x] = true;
               q.push_front(next);
            }
            else if (i == 2) {
               if (next.right > 0) {
                  next.right -= 1;
                  visited[next.y][next.x] = true;
                  q.push_back(next);
               }
               else continue;
            }
            else {
               if (next.left > 0){
                  next.left -= 1;
                  visited[next.y][next.x] = true;
                  q.push_back(next);
               }
               else continue;
            }
         }
      }
   }
   for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
         if (visited[y][x]) {
            ans++;
         }
      }
   }
   cout << ans;
   return 0;
}
