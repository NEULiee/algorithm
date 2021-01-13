#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visit[9];

void backtracking(int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    for (int i=1; i<=N; i++) {
        if (!visit[i]) {
            if ((cnt > 0 && i > arr[cnt - 1]) || cnt == 0) {
                visit[i] = true;
                arr[cnt] = i;
                backtracking(cnt + 1);
                visit[i] = false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    backtracking(0);
    return 0;
}
