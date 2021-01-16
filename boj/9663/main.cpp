//
//  main.cpp
//  9663 N-Queen (backtracking)
//
//  Created by Ha Neul Iee on 2021/01/16.
//

#include <iostream>
using namespace std;

int N, cnt;
int board[15];

bool isSetQueen(int row) {
    for (int i=0; i<row; i++) {
        if (board[i] == board[row] || (row - i) == abs(board[row] - board[i])) {
            return false;
        }
    }
    return true;
}

void setQueen(int row) {
    if (row == N) {
        cnt++;
        return;
    }
    for (int i=0; i<N; i++) {
        board[row] = i;
        if (isSetQueen(row)) {
            setQueen(row + 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    setQueen(0);
    cout << cnt << "\n";
    return 0;
}
