#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];

void backtracking(int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i=1; i<=N; i++) {
        if (cnt == 0 || (arr[cnt - 1] <= i)) {
            arr[cnt] = i;
            backtracking(cnt + 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    backtracking(0);
    return 0;
}
