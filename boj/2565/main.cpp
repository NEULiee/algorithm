//
//  main.cpp
//  2565 전깃줄 (LIS 응용)
//
//  Created by Ha Neul Iee on 2021/02/04.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int N, a, b;
vector<pii> e;
vector<int> lis;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a >> b;
        e.push_back(make_pair(a, b));
    }
    sort(e.begin(), e.end());
    for (int i=0; i<N; i++) {
        if (lis.empty() || lis.back() < e[i].second) {
            lis.push_back(e[i].second);
        }
        else {
            int idx = (int)(lower_bound(lis.begin(), lis.end(), e[i].second) - lis.begin());
            lis[idx] = e[i].second;
        }
    }
    cout << N - (int)(lis.size()) << "\n";
    
    return 0;
}
