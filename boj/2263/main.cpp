//
//  main.cpp
//  2263 트리의 순회 (트리)
//
//  Created by Ha Neul Iee on 2021/01/21.
//

#include <iostream>
using namespace std;

int n;
int idx[100000], inorder[100000], postorder[100000];

void preorder(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inBegin > inEnd || postBegin > postEnd) {
        return;
    }
    int root = postorder[postEnd];
    cout << root << " ";
    preorder(inBegin, idx[root] - 1, postBegin, postBegin + idx[root] - inBegin - 1);
    preorder(idx[root] + 1, inEnd, postBegin + idx[root] - inBegin, postEnd - 1);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    for (int i=0; i<n; i++) {
        cin >> postorder[i];
    }
    for (int i=0; i<n; i++) {
        idx[inorder[i]] = i;
    }
    preorder(0, n-1, 0, n-1);
    cout << "\n";
    return 0;
}
