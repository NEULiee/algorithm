//
//  main.cpp
//  14889 스타트와 링크 (백트래킹)
//
//  Created by Ha Neul Iee on 2021/01/16.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, S[21][21], team[21], minStats = 1000000, teamStats1, teamStats2;

void subStats() {
    teamStats1 = 0;
    teamStats2 = 0;
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            if (team[i] == 0 && team[j] == 0) {
                teamStats1 += S[i][j];
            }
            else if (team[i] == 1 && team[j] == 1) {
                teamStats2 += S[i][j];
            }
        }
    }
}

void backtracking(int memberCount, int member) {
    if (memberCount == N/2) {
        subStats();
        minStats = min(minStats, abs(teamStats1 - teamStats2));
        return;
    }
    for (int i = member + 1; i<N; i++) {
        if (team[i] != 1) {
            team[i] = 1;
            backtracking(memberCount + 1, i);
            team[i] = 0;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> S[i][j];
            if (i > j) {
                S[j][i] += S[i][j];
            }
        }
    }
    backtracking(0, 0);
    cout << minStats << "\n";
    return 0;
}

