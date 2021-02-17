//
//  main.cpp
//  1311_noRef 할일 정하기 1
//
//  Created by Ha Neul Iee on 2021/02/16.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, D[20][20], dp[1 << 20];

int rec(int num, int work) {
    if (num == N) {
        return 0;
    }
    if (dp[work] != -1) {
        return dp[work];
    }
    dp[work] = 1e9;
    for (int i=0; i<N; i++) {
        if (!(work & (1 << i))) {
            dp[work] = min(dp[work], D[num][i] + rec(num + 1, work | (1 << i)));
        }
    }
    return dp[work];
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
    memset(dp, -1, sizeof(dp));
    int res = 1e9;
    
    for (int i=0; i<N; i++) {
        res = min(res, D[0][i] + rec(1, 1 << i));
    }
    cout << res << "\n";
    
    return 0;
}
