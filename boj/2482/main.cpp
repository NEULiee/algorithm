//
//  main.cpp
//  2482 색상환 (dp bitmask)
//
//  Created by Ha Neul Iee on 2021/02/21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long num = 1e9 + 3;

int N, K;
long dp[1001][1001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie();  cout.tie();
    
    cin >> N >> K;
    
    for (int i=0; i<=N; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    
    for (int i=2; i<=N; i++) {
        for (int j=2; j<=K; j++) {
            if (i == N && j == K) {
                dp[i][j] = (dp[i-3][j-1] + dp[i-1][j]) % num;
                continue;
            }
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % num;
        }
    }
    cout << dp[N][K] << "\n";
    return 0;
}
