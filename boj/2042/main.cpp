//
//  main.cpp
//  2042 구간 합 구하기 (세그먼트 트리)
//
//  Created by Ha Neul Iee on 2021/02/23.
//
//  node가 담당하고 있는 구간 : start, end
//  합을 구해야하는 구간 : left, right

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll N, M, K, input, a, b, c;

ll init(vector<ll> &arr, vector<ll> &tree, ll node, ll start, ll end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(arr, tree, node*2, start, (start+end)/2) + init(arr, tree, node*2+1, (start+end)/2+1, end);
    }
}

ll sum(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right) {
    if (end < left || start > right) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

void update(vector<ll> &tree, ll node, ll start, ll end, ll index, ll diff) {
    if (index < start || end < index) {
        return;
    }
    tree[node] += diff;
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    
    cin >> N >> M >> K;
    
    vector<ll> arr(N);
    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h+1));
    vector<ll> tree(treeSize);
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    init(arr, tree, 1, 0, N-1);
    
    for (int i=0; i<M+K; i++) {
        cin >> a >> b >> c;
        if (a==1) {
            ll diff = c - arr[b-1];
            arr[b-1] = c;
            update(tree, 1, 0, N-1, b-1, diff);
        }
        else if (a==2) {
            cout << sum(tree, 1, 0, N-1, b-1, c-1) << "\n";
        }
    }
    
    return 0;
}
