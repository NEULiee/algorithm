//
//  main.cpp
//  11659 구간 합 구하기 4
//
//  Created by Ha Neul Iee on 2021/02/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, arr[100000], sum = 0, start, end;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        if (i>0) {
            arr[i] += arr[i-1];
        }
    }
    for (int i=0; i<M; i++) {
        sum = 0;
        cin >> start >> end;
        if (start == 1) {
            cout << arr[end-1] << "\n";
        }
        else {
            cout << arr[end-1] - arr[start-2] << "\n";
        }
    }
    return 0;
}
