//
//  main.cpp
//  2110 공유기 설치 (이분탐색)
//
//  Created by Ha Neul Iee on 2021/01/29.
//
//  답이 x 이상일 수 있는가 ? -> 이분탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, C;
vector<ll> house;

bool isSetOk(ll dist) {
    ll d, start = house[0], cnt = 1;
    for (int i=1; i<N; i++) {
        d = house[i] - start;
        if (d >= dist) {
            cnt++;
            start = house[i];
        }
    }
    if (cnt >= C) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll start, end, mid, res = 0, input;
    cin >> N >> C;
    for (int i=0; i<N; i++) {
        cin >> input;
        house.push_back(input);
    }
    sort(house.begin(), house.end());
    start = 0;
    end = house[N-1] - house[0];
    
    while (start <= end) {
        mid = (start + end) / 2;
        if (isSetOk(mid)) {
            if (res < mid) {
                res = mid;
            }
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
