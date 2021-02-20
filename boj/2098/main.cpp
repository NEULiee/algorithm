//
//  main.cpp
//  2098 외판원 순회 (dp)
//
//  Created by Ha Neul Iee on 2021/02/13.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, W[16][16], dp[16][(1 << 16) + 1], minValue = 1e9;

int rec(int cur, int road) {
    if (road == (1 << N) - 1) {
        return W[cur][0] ? W[cur][0] : 1e9;
    }
    if (dp[cur][road] != -1) {
        return dp[cur][road];
    }
    dp[cur][road] = 1e9;
    for (int i=0; i<N; i++) {
        if (W[cur][i] == 0){
            continue;
        }
        if (!(road & (1 << i))) {
            dp[cur][road] = min(dp[cur][road], W[cur][i] + rec(i, road | (1 << i)));
        }
    }
    return dp[cur][road];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> W[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    
    cout << rec(0, 1) << "\n";
}
