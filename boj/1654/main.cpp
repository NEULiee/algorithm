//
//  main.cpp
//  1654 랜선 자르기 (이분탐색)
//
//  Created by Ha Neul Iee on 2021/01/28.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int K, N;
ull input, minLength, maxLength, mid, res;
vector<ull> lan;

int countOfLan(ull length) {
    int cnt = 0;
    for (int i=0; i<K; i++) {
        cnt += lan[i] / length;
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> K >> N;
    for (int i=0; i<K; i++) {
        cin >> input;
        lan.push_back(input);
    }
    sort(lan.begin(), lan.end());
    
    // 랜선의 길이를 left, right, mid
    minLength = 1;
    maxLength = lan[K-1];
    mid = lan[K-1];
    
    while (minLength <= maxLength) {
        mid = (minLength + maxLength) / 2;
        if (countOfLan(mid) >= N) {
            res = mid;
            minLength = mid + 1;
        }
        else {
            maxLength = mid - 1;
        }
    }
    cout << res << "\n";
    return 0;
}
