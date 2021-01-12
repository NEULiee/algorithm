#include <iostream>
#include <algorithm>
using namespace std;

int T, n, dp[11];

int main(int argc, const char * argv[]) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i=4; i<=11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    cin >> T;
    while(T--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}
