//
//  main.cpp
//  7579 앱 (knapsack)
//
//  Created by Ha Neul Iee on 2021/08/09.
//

#include <iostream>
#include <algorithm>
using namespace std;

// i번째 앱까지 걸리는 시간

int N, M, sum, res=1e9, memory[101], cost[101], dp[101][10001];

int main() {
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> memory[i];
    }
    for (int i=1; i<=N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=sum; j++) {
            if (cost[i] <= j) {
                dp[i][j] = max(dp[i-1][j-cost[i]] + memory[i], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
            if (dp[i][j] >= M) {
                res = min(res, j);
            }
        }
    }
    
    cout << res << "\n";
}
