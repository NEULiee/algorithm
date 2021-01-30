//
//  main.cpp
//  1300 K번째 수 (이분탐색)
//
//  Created by Ha Neul Iee on 2021/01/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {
    ll N, k, start, end, mid, cnt = 0, res = 0;
    cin >> N >> k;
    start = 1;
    end = k;
    while (start <= end) {
        mid = (start + end) / 2;
        for (int i=1; i<=N; i++) {
            cnt += min(N, mid / i);
        }
        if (cnt >= k) {
            res = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        cnt = 0;
    }
    cout << res << "\n";
    return 0;
}
