//
//  main.cpp
//  7568 덩치
//
//  Created by Ha Neul Iee on 2021/01/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main(int argc, const char * argv[]) {
    vector<pii> v;
    int rank[51] = {0};
    int N, x, y;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i=0; i<N; i++) {
        int k=1;
        for (int j=0; j<N; j++) {
            if (i != j) {
                if (v[i].first < v[j].first && v[i].second < v[j].second) {
                    k++;
                }
            }
        }
        rank[i] = k;
    }
    
    for (int i=0; i<N; i++) {
        cout << rank[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
