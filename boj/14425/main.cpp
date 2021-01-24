//
//  main.cpp
//  14425 문자열 집합 (트라이)
//
//  Created by Ha Neul Iee on 2021/01/24.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define SIZE 26

int N, M;
string input;

struct Trie {
    Trie *next[SIZE];
    bool isFinish;
    bool haveChild;
    
    Trie() {
        fill(next, next + SIZE, nullptr);
        isFinish = haveChild = false;
    }
    ~Trie() {
        for (int i=0; i<SIZE; i++) {
            if (next[i]) {
                delete next[i];
            }
        }
    }
    
    void insert(string &word, int wordSize, int index) {
        if (wordSize <= index) {
            isFinish = true;
            return;
        }
        int wordNum = word.at(index) - 'a';
        if (next[wordNum] == NULL) {
            next[wordNum] = new Trie();
            haveChild = true;
        }
        next[wordNum]->insert(word, wordSize, index + 1);
    }
    
    bool find(string &word, int wordSize, int index) {
        bool result = false;
        if (wordSize <= index) {
            if (isFinish) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            int wordNum = word.at(index) - 'a';
            if (next[wordNum] == NULL) {
                return false;
            }
            result = next[wordNum]->find(word, wordSize, index + 1);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    Trie root;
    for (int i=0; i<N; i++) {
        cin >> input;
        root.insert(input, (int)input.size(), 0);
    }
    int cnt = 0;
    for (int i=0; i<M; i++) {
        cin >> input;
        if (root.find(input, (int)input.size(), 0)){
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
