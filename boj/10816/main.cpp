//
//  main.cpp
//  10816 숫자 카드 2 (이분탐색)
//
//  Created by Ha Neul Iee on 2021/01/26.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, input;
int card[500000];

int lower_bound(int num) {
    int first = 0, last = N - 1, mid;
    while (last > first) {
        mid = (first + last) / 2;
        if (card[mid] >= num) {
            last = mid;
        }
        else {
            first = mid + 1;
        }
    }
    return last;
}

int upper_bound(int num) {
    int first = 0, last = N - 1, mid;
    while (last > first) {
        mid = (first + last) / 2;
        if (card[mid] > num) {
            last = mid;
        }
        else {
            first = mid + 1;
        }
    }
    return last;
}

int countOfCard(int num) {
    return upper_bound(num) - lower_bound(num);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> card[i];
    }
    sort(card, card + N);
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> input;
        int lower = lower_bound(input);
        int upper = upper_bound(input);
        if (upper == N-1 && card[N-1] == input) {
            upper++;
        }
        cout << upper - lower << " ";
    }
    cout << "\n";
    return 0;
}
