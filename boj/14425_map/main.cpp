//
//  main.cpp
//  14425 문자열 탐색 (map)
//
//  Created by Ha Neul Iee on 2021/01/24.
//

#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

int N, M, cnt;
string input;
unordered_set<string> s;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> input;
        s.insert(input);
    }
    for (int i=0; i<M; i++) {
        cin >> input;
        if (s.find(input) != s.end()) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
