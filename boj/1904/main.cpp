//
//  main.cpp
//  1904 01타일 (dp)
//
//  Created by Ha Neul Iee on 2021/02/02.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define NUM 15746

int dp[1000001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i=3; i<=1000000; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[N] << "\n";
    return 0;
}
