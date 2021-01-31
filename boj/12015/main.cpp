//
//  main.cpp
//  11053 가장 긴 증가하는 부분수열
//  12015 가장 긴 증가하는 부분 수열 2 (이분탐색)
//  12738 가장 긴 증가하는 부분 수열 3
//  LIS 구하기 ! -> list 한개로 구현하기
//
//  Created by Ha Neul Iee on 2021/01/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll input;
vector<ll> lis;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> input;
        if (lis.empty() || lis.back() < input) {
            lis.push_back(input);
        }
        else {
            int index = (int)(lower_bound(lis.begin(), lis.end(), input) - lis.begin());
            lis[index] = input;
        }
    }
    cout << lis.size() << "\n";
    return 0;
}
