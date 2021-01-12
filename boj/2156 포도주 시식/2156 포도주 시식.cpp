#include <iostream>
#include <algorithm>
using namespace std;

int n, drink[10001], dp[10001], max_drink = 0;

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> drink[i];
    }
    
    dp[1] = drink[1];
    dp[2] = drink[1] + drink[2];
    for (int i=3; i<=n; i++) {
        dp[i] = max(dp[i-2] + drink[i], dp[i-3] + drink[i-1] + drink[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    
    cout << dp[n] << "\n";
    return 0;
}
