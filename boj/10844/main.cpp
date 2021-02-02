//
//  main.cpp
//  10844 쉬운 계단 수 (dp)
//
//  Created by Ha Neul Iee on 2021/02/02.
//

#include <iostream>
using namespace std;

typedef long long ll;
#define NUM 1000000000

ll dp[101][10];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    dp[1][0] = 0;
    for (int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }
    for (int i=2; i<=100; i++) {
        for (int j=0; j<=9; j++) {
            if (j==0) {
                dp[i][j] = dp[i-1][j+1] % NUM;
            }
            else if (j==9) {
                dp[i][j] = dp[i-1][j-1] % NUM;
            }
            else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % NUM;
            }
        }
    }
    int N, cnt = 0;
    cin >> N;
    for (int i=0; i<=9; i++) {
        cnt += dp[N][i];
        cnt %= NUM;
    }
    cout << (cnt % NUM) << "\n";
    return 0;
}
