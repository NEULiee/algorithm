//
//  main.cpp
//  1436 영화감독 숌
//
//  Created by Ha Neul Iee on 2021/01/10.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, cnt = 0, i=666;
    cin >> N;
    while(1) {
        string s = to_string(i);
        for (int j=0; j<(int)s.size()-2; j++) {
            if(s[j] == '6' && s[j+1] == '6' && s[j+2] == '6') {
                cnt++;
                break;
            }
        }
        if (cnt == N) {
            cout << i << "\n";
            return 0;
        }
        i++;
    }
}



