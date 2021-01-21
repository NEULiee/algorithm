//
//  main.cpp
//  1991 트리 순회 (트리)
//
//  Created by Ha Neul Iee on 2021/01/21.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
char A, B, C, tree[26][2];

void preorder(int root) {
    cout << char(root + 'A');
    if ('A' <= tree[root][0] && tree[root][0] <= 'Z') {
        preorder(tree[root][0] - 'A');
    }
    if ('A' <= tree[root][1] && tree[root][1] <= 'Z') {
        preorder(tree[root][1] - 'A');
    }
}

void inorder(int root) {
    if ('A' <= tree[root][0] && tree[root][0] <= 'Z') {
        inorder(tree[root][0] - 'A');
    }
    cout << char(root + 'A');
    if ('A' <= tree[root][1] && tree[root][1] <= 'Z') {
        inorder(tree[root][1] - 'A');
    }
}

void postorder(int root) {
    if ('A' <= tree[root][0] && tree[root][0] <= 'Z') {
        postorder(tree[root][0] - 'A');
    }
    if ('A' <= tree[root][1] && tree[root][1] <= 'Z') {
        postorder(tree[root][1] - 'A');
    }
    cout << char(root + 'A');
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A >> B >> C;
        if (B != '.' || C != '.') {
            tree[A - 'A'][0] = B;
            tree[A - 'A'][1] = C;
        }
        else if (B != '.' || C == '.') {
            tree[A - 'A'][0] = B;
            
        }
        else if (B == '.' || C != '.') {
            tree[A - 'A'][1] = C;
        }
        
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
    return 0;
}
