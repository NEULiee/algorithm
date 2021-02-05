//
//  main.cpp
//  1912 연속합
//
//  Created by Ha Neul Iee on 2021/02/05.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int dp[100000];

int main(int argc, const char * argv[]) {
    int maxValue = -1e9;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for (int i=1; i<n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }
    for (int i=0; i<n; i++) {
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue << "\n";
    return 0;
}
