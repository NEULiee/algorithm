//
//  main.cpp
//  9184 신나는 함수 실행 (dp)
//
//  Created by Ha Neul Iee on 2021/02/01.
//

#include <iostream>
using namespace std;

const int MAX = 21;

int dp[MAX][MAX][MAX];

int main() {
    int a=0, b=0, c=0;
    
    for (int i=0; i<=20; i++) {
        for (int j=0; j<=20; j++) {
            for (int k=0; k<=20; k++) {
                if (i==0 || j==0 || k==0) {
                    dp[i][j][k] = 1;
                }
                else if (a<b && b<c) {
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i-1][j][k];
                }
                else {
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                }
            }
        }
    }
    
    while (1) {
        cin >> a >> b >> c;
        if (a==-1 && b==-1 && c==-1) {
            return 0;
        }
        else {
            cout << "w(" << a << ", " << b << ", " << c << ") = ";
            if (a<=0 || b<=0 || c<=0) {
                cout << 1 << "\n";
            }
            else if (a>20 || b>20 || c>20) {
                cout << dp[20][20][20] << "\n";
            }
            else {
                cout << dp[a][b][c] << "\n";
            }
        }
    }
}
