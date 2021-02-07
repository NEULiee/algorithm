//
//  main.cpp
//  11066 파일 합치기
//
//  Created by Ha Neul Iee on 2021/02/07.
//

#include <iostream>
#include <algorithm>
using namespace std;

int T, K, dp[501][501],cost[501], sum[501];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> K;
        for (int i=1; i<=K; i++) {
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        
        for (int d = 1; d < K; ++d) {
            for (int tx = 1; tx + d <= K; ++tx) {
                int ty = tx + d;
                dp[tx][ty] = 1e9;
                
                for (int mid = tx; mid < ty; ++mid)
                dp[tx][ty] =
                min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
            }
        }
        
        cout << dp[1][K] << "\n";
    }
    return 0;
}
