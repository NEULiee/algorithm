//
//  main.cpp
//  14725 개미굴
//
//  Created by Ha Neul Iee on 2021/01/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int N, K;
vector<string> name;

struct Trie {
    map<string, Trie*> next;
    
    void insert(vector<string>& strVector, int strSize, int index) {
        if (strSize <= index) {
            return;
        }
        map<string, Trie*>::iterator iter = next.find(strVector[index]);
        if (iter == next.end()) {
            Trie* newNext = new Trie;
            next.insert({strVector[index], newNext});
            newNext->insert(strVector, strSize, index + 1);
        }
        else {
            iter->second->insert(strVector, strSize, index + 1);
        }
    }
    
    void print(int level) {
        for (auto& food : next) {
            for (int i=0; i<level; i++) {
                cout << "--";
            }
            cout << food.first << "\n";
            food.second->print(level + 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    string input;
    Trie root;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> K;
        name.clear();
        for (int j=0; j<K; j++) {
            cin >> input;
            name.push_back(input);
        }
        root.insert(name, (int)name.size(), 0);
    }
    root.print(0);
    return 0;
}
