//
//  main.cpp
//  11723 집합
//
//  Created by Ha Neul Iee on 2021/02/12.
//

#include <iostream>
#include <string>
using namespace std;

int M, num, bit;
string input;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M;
    while (M--) {
        cin >> input;
        if (input == "add") {
            cin >> num;
            bit |= (1 << num);
        }
        else if (input == "remove") {
            cin >> num;
            bit &= ~(1 << num);
        }
        else if (input == "check") {
            cin >> num;
            if (bit & (1 << num)) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (input == "toggle") {
            cin >> num;
            if (bit & (1 << num))
                bit &= ~(1 << num);
            else
                bit |= (1 << num);
        }
        else if (input == "all") {
            bit = (1 << 21) - 1;
        }
        else if (input == "empty") {
            bit = 0;
        }
    }
    
    return 0;
}
