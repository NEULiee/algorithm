//
//  main.cpp
//  1311 할 일 정하기 1
//
//  Created by Ha Neul Iee on 2021/02/16.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, D[20][20], dp[1 << 20], res;

int rec(int num, int work) {
    if (num == N) {
        return 0;
    }
    int &temp = dp[work];
    if (temp != -1) {
        return temp;
    }
    temp = 1e9;
    
    for (int i=0; i<N; i++) {
        if (!(work & (1 << i))) {
            temp = min(temp, D[num][i] + rec(num + 1, work | (1 << i)));
        }
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> D[i][j];
        }
    }
    // fill(dp, dp + (1 << 20), -1);
    memset(dp, -1, sizeof(dp));
    res = 1e9;
    for (int i=0; i<N; i++) {
        res = min(res, D[0][i] + rec(1, 1 << i));
    }
    cout << res << "\n";
    return 0;
}
