//
//  main.cpp
//  2231 분해합
//
//  Created by Ha Neul Iee on 2021/01/10.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        int sum = i;
        string a = to_string(i);
        for (int i=0; i<a.size(); i++) {
            sum += a[i] - '0';
        }
        if (sum == N) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}
