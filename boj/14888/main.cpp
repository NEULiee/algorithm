//
//  main.cpp
//  14888 연산자 끼워넣기 (백트래킹)
//
//  Created by Ha Neul Iee on 2021/01/17.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, minValue = 1e9, maxValue = -1e9;
int A[11];
int cal[4];

void dfs(int count, int result) { // 연산자 count
    if (count == N-1) {
        minValue = min(minValue, result);
        maxValue = max(maxValue, result);
        return;
    }
    for (int i=0; i<4; i++) {
        if (cal[i] > 0) {
            cal[i]--;
            if (i == 0) {
                dfs(count + 1, result + A[count+1]);
            }
            else if (i == 1) {
                dfs(count + 1, result - A[count+1]);
            }
            else if (i == 2) {
                dfs(count + 1, result * A[count+1]);
            }
            else if (i == 3) {
                dfs(count + 1, result / A[count+1]);
            }
            cal[i]++;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N ;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    for (int i=0; i<4; i++) {
        cin >> cal[i];
    }
    dfs(0, A[0]);
    cout << maxValue << "\n" << minValue << "\n";
    return 0;
}
