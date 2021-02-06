//
//  main.cpp
//  12865 평범한 배낭 (DP)
//
//  Created by Ha Neul Iee on 2021/02/06.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, W[101], V[101];
int value[101][100001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            if (j >= W[i]) {
                value[i][j] = max(value[i-1][j], value[i-1][j-W[i]] + V[i]);
            }
            else {
                value[i][j] = value[i-1][j];
            }
        }
    }
    
    
    cout << value[N][K] << "\n";
    return 0;
}
