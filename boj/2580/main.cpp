//
//  main.cpp
//  2580 스도쿠 (백트래킹)
//
//  Created by Ha Neul Iee on 2021/01/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int sudoku[9][9], zeroCount;
vector<pii> zero;

bool IsRowOK(int x, int num) {
    for (int i=0; i<9; i++) {
        if (sudoku[x][i] == num) {
            return false;
        }
    }
    return true;
}

bool IsColOK(int y, int num) {
    for (int i=0; i<9; i++) {
        if (sudoku[i][y] == num) {
            return false;
        }
    }
    return true;
}

bool IsSquareOK(int x, int y, int num) {
    for (int i=((x/3)*3); i<3+((x/3)*3); i++) {
        for (int j=((y/3)*3); j<3+((y/3)*3); j++) {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

void backtracking(int count) {
    if (count == zeroCount) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    
    int x = zero[count].first;
    int y = zero[count].second;
    for (int i=1; i<=9; i++) {
        if (IsRowOK(x, i) && IsColOK(y, i) && IsSquareOK(x, y, i)) {
            sudoku[x][y] = i;
            backtracking(count + 1);
            sudoku[x][y] = 0;
        }
    }
}

int main() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                zero.push_back(make_pair(i, j));
                zeroCount++;
            }
        }
    }
    backtracking(0);
    return 0;
}
