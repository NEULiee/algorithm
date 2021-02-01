//
//  main.cpp
//  1003 피보나치 함수 (DP)
//
//  Created by Ha Neul Iee on 2021/02/01.
//

#include <iostream>
using namespace std;

int dp0[41];
int dp1[41];

int main(int argc, const char * argv[]) {
    int T, N;
    cin >> T;
    dp0[0] = 1;
    dp1[1] = 1;
    for (int i=2; i<=40; i++) {
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    }
    while (T--) {
        cin >> N;
        cout << dp0[N] << " " << dp1[N] << "\n";
    }
    return 0;
}
