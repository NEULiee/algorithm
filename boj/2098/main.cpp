//
//  main.cpp
//  2098 외판원 순회 (dp)
//
//  Created by Ha Neul Iee on 2021/02/13.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, W[16][16], dp[16][(1 << 16) + 1];

int dfs(int cur, int curVisited) {
    if (curVisited == (1 << N) - 1) {
        return W[cur][0] == 0 ? 1e9 : W[cur][0];
    }
    if (dp[cur][curVisited] != 1e9) {
        return dp[cur][curVisited];
    }
    for (int i=0; i<N; i++) {
        if (curVisited & (1 << i)) {
            continue;
        }
        if (W[cur][i] == 0) {
            continue;
        }
        dp[cur][curVisited] = min(dp[cur][curVisited], dfs(1, (curVisited | (1 << i)) + W[cur][i]));
        return dp[cur][curVisited];
    }
    return 0;
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
    for (int i=0; i<16; i++) {
        for (int j=0; j< ((1 << N) -1); j++) {
            dp[i][j] = 1e9;
        }
    }

    cout << dfs(0, 1);
    return 0;
}
