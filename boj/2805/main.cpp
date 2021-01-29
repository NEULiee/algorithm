//
//  main.cpp
//  2805 나무 자르기 (이분탐색)
//
//  Created by Ha Neul Iee on 2021/01/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M, input;
vector<ll> treeHeight;

ll getTree(ll height) {
    ll res = 0;
    for (int i=0; i<N; i++) {
        ll t = treeHeight[i] - height;
        if (t > 0) {
            res += t;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll start, end, mid, res = 0;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> input;
        treeHeight.push_back(input);
    }
    sort(treeHeight.begin(), treeHeight.end());
    start = 0;
    end = treeHeight[N-1];
    while (start <= end) {
        mid = (start + end) / 2;
        if (getTree(mid) >= M) {
            res = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << res << "\n";
    
    return 0;
}
