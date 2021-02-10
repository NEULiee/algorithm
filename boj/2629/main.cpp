//
//  main.cpp
//  2629 양팔저울 (DP)
//
//  Created by Ha Neul Iee on 2021/02/07.
//

#include <iostream>
#include <algorithm>
using namespace std;

int sinkerCount, sinkerWeight[31], marbleCount, marbleWeight[8];
bool isPossible;
bool isWeight[31][55001];

void check(int cnt, int weight) {
    if (cnt > sinkerCount) {
        return;
    }
    if (isWeight[cnt][weight]) {
        return;
    }
    else {
        isWeight[cnt][weight] = true;
    }
    
    check(cnt + 1, weight + sinkerWeight[cnt]);
    check(cnt + 1, weight);
    check(cnt + 1, weight - sinkerWeight[cnt]);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> sinkerCount;
    for (int i=0; i<sinkerCount; i++) {
        cin >> sinkerWeight[i];
    }
    cin >> marbleCount;
    for (int i=0; i<marbleCount; i++) {
        cin >> marbleWeight[i];
    }
    check(0, 40000);
    
    for (int i=0; i<marbleCount; i++) {
        isPossible = false;
        for (int j=1; j<=sinkerCount; j++) {
            if (isWeight[j][40000 + marbleWeight[i]]) {
                cout << "Y ";
                isPossible = true;
                break;
            }
        }
        if (isPossible == false) {
            cout << "N ";
        }
    }
    
    return 0;
}
