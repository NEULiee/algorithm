//
//  main.cpp
//  2293 동전 1 (dp)
//
//  Created by Ha Neul Iee on 2021/02/11.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, k, value[100], dp[10001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> value[i];
    }
    
    dp[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=value[i]; j<=k; j++) {
            if (j - value[i] >= 0) {
                dp[j] += dp[j - value[i]];
            }
        }
    }
    
    cout << dp[k] << "\n";
    return 0;
}
