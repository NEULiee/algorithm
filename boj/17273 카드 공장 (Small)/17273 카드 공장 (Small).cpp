//
//  main.cpp
//  17273 카드 공장 (Small)
//
//  Created by Ha Neul Iee on 2021/01/06.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A, B, K, front_back;
int main(int argc, const char * argv[]) {
    cin >> N >> M;
    cin >> A >> B;
    front_back = 0;
    for (int i=0; i<M; i++) {
        cin >> K;
        if (!front_back && A <= K) {
            front_back = 1;
        }
        else if (front_back && B <= K) {
            front_back = 0;
        }
    }
    if (!front_back) {
        cout << A << "\n";
    }
    else {
        cout << B << "\n";
    }
}
