//
//  main.cpp
//  1018 체스판 다시 칠하기
//
//  Created by Ha Neul Iee on 2021/01/10.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
char board[51][51];
char white[8][8];
char black[8][8];

bool isIn(int x, int y) {
    return (x+7) < N && (y+7) < M;
}

int square(int x, int y) {
    int w=0, b=0;
    if (isIn(x, y)) {
        for (int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if (board[x+i][y+j] == white[i][j]) {
                    w++;
                }
                if (board[x+i][y+j] == black[i][j]) {
                    b++;
                }
            }
        }
    }
    else {
        return 0;
    }
    return max(w, b);
}

int main(int argc, const char * argv[]) {
    string input;
    cin >> N >> M;
    
    for (int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if (i%2 == 0 && j%2 == 0) {
                white[i][j] = 'W';
                black[i][j] = 'B';
            }
            else if (i%2 == 1 && j%2 == 0) {
                white[i][j] = 'B';
                black[i][j] = 'W';
            }
            else if (i%2 == 0 && j%2 == 1) {
                white[i][j] = 'B';
                black[i][j] = 'W';
            }
            else {
                white[i][j] = 'W';
                black[i][j] = 'B';
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        cin >> input;
        for (int j=0; j<input.size(); j++) {
            board[i][j] = input[j];
        }
    }
    
    int res=0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            res = max(res, square(i, j));
        }
    }
    
    cout << 64-res << "\n";
    return 0;
}
