//
//  main.cpp
//  9461 파도반 수열
//
//  Created by Ha Neul Iee on 2021/02/02.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll dp[101];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for (int i=5; i<=100; i++) {
        dp[i] = dp[i-3] + dp[i-2];
    }
    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }
    
    return 0;
}
