//
//  main.cpp
//  1655 가운데를 말해요 (max_heap, min_heap)
//
//  Created by Ha Neul Iee on 2021/02/08.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, num;
priority_queue<int> small;  // max heap
priority_queue<int, vector<int>, greater<int>> big; // min heap

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> num;
    small.push(num);
    cout << num << "\n";
    N--;
    while (N--) {
        cin >> num;
        if (num < small.top()) {
            small.push(num);
        }
        else {
            big.push(num);
        }
        
        if ((int)small.size() < (int)big.size()) {
            small.push(big.top());
            big.pop();
        }
        else if ((int)small.size() > (int)big.size() + 1) {
            big.push(small.top());
            small.pop();
        }
        
        cout << small.top() << "\n";
    }
    
    return 0;
}
