//
//  main.cpp
//  11054 가장 긴 바이토닉 부분 수열
//
//  Created by Ha Neul Iee on 2021/02/03.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, arr[1000], dp_bottomUp[1000], dp_topDown[1000];
vector<int> lis;

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    for (int i=0; i<N; i++) {
        if (lis.empty()) {
            lis.push_back(arr[i]);
        }
        else if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
        }
        else {
            int idx = (int)(lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin());
            lis[idx] = arr[i];
        }
        dp_bottomUp[i] = (int)lis.size();
    }
    lis.clear();
    
    for (int i=N-1; i>=0; i--) {
        if (lis.empty()) {
            lis.push_back(arr[i]);
        }
        else if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
        }
        else {
            int idx = (int)(lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin());
            lis[idx] = arr[i];
        }
        dp_topDown[i] = (int)lis.size();
    }
    
    vector<int> res;
    for (int i=0; i<N; i++) {
        res.push_back(dp_bottomUp[i] + dp_topDown[i]);
    }
    sort(res.begin(), res.end());
    
    cout << res.back()-1 << "\n";

    return 0;
}
