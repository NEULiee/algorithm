//
//  main.cpp
//  14002 가장 긴 증가하는 부분 수열 4 (이분탐색)
//  14003 가장 긴 증가하는 부분 수열 5
//
//  Created by Ha Neul Iee on 2021/01/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, input, idx[1000000], arr[1000000], c[1000000];
vector<ll> lis;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int currentIdx;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> input;
        arr[i] = input;
        if (lis.empty() || lis.back() < input) {
            lis.push_back(input);
            currentIdx = (int)lis.size() - 1;
        }
        else {
            currentIdx = (int)(lower_bound(lis.begin(), lis.end(), input) - lis.begin());
            lis[currentIdx] = input;
        }
        idx[i] = currentIdx;
    }
    
    currentIdx = (int)lis.size() - 1;
    for (int i=N-1; i>=0; i--) {
        if (idx[i] == currentIdx) {
            c[currentIdx] = arr[i];
            currentIdx--;
            if (currentIdx < 0) {
                break;
            }
        }
    }
    cout << lis.size() << "\n";
    for (int i=0; i<(int)lis.size(); i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    return 0;
}
